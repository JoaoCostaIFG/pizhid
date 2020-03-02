/*
 * This program convers strings/chars given in argv to the code used by
 * keyboards on keypress Can be used, for example, on a raspberry pi that is
 * acting as an HID gadget (FSconfig) to act as a keyboard on a connected device
 * (with USB OTG)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "keys.h"

#define _XOPEN_SOURCE 700

void sleep_ms(int milliseconds) {
  /* pause execution for milliseconds ms */
  struct timespec ts;

  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
}

void release_keys(FILE *fp) {
  fprintf(fp,"%c%c%c%c%c%c%c%c", '\0', '\0', '\0', '\0', '\0', '\0', '\0',
          '\0');
}

void write_key(char modifier, char keytowrite, FILE *fp) {
  /* press key */
  fprintf(fp, "%c%c%c%c%c%c%c%c", modifier, '\0', keytowrite, '\0', '\0', '\0',
          '\0', '\0');

  /* release key */
  /* release_keys(fp); */
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fputs("Usage: piz_hid-keyboard <layout> <text>\n", stderr);
    exit(1);
  }

  int i, j; // for loop indexes
  short unsigned int lay = atoi(argv[1]);
  FILE *fp;
  fp = fopen("/dev/hidg0", "w");

  for (i = 2; i < argc; i++) {
    for (j = 0; j < strlen(argv[i]); j++) {
      write_key(layout[argv[i][j]].keys[lay].modifier,
                layout[argv[i][j]].keys[lay].keytowrite, fp);
      if (layout[argv[i][j]].keys[lay].is_dead)
        write_key(layout[argv[i][j]].keys[lay].modifier,
                  layout[argv[i][j]].keys[lay].keytowrite, fp);
    }

    if (i < argc - 2)
      write_key(layout[' '].keys[lay].modifier,
                layout[' '].keys[lay].keytowrite, fp); // white space
  }

  release_keys(fp);
  fclose(fp);
  return 0;
}
