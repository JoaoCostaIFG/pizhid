/*
 * This program convers strings/chars given in argv to the code used by
 * keyboards on keypress Can be used, for example, on a raspberry pi that is
 * acting as an HID gadget (FSconfig) to act as a keyboard on a connected
 * device (with USB OTG)
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keys.h"

#define START_I 2
#define SUCCESS_WRITE 8
#define INSERT_KEY(dev, mod, chr)                                              \
  fprintf(dev, "%c%c%c%c%c%c%c%c", mod, '\0', chr, '\0', '\0', '\0', '\0', '\0')
#define RELEASE_KEYS(dev) INSERT_KEY(fp, '\0', '\0')

void write_key(struct Key *key, FILE *fp) {
  /* press key */
  if (INSERT_KEY(fp, key->modifier, key->chr) != SUCCESS_WRITE) {
    fputs("Key output failed.\n", stderr);
    exit(1);
  }
  /* dead keys need to be pressed twice */
  if (key->is_dead) {
    RELEASE_KEYS(fp);
    if (INSERT_KEY(fp, key->modifier, key->chr) != SUCCESS_WRITE) {
      fputs("Key output failed.\n", stderr);
      exit(1);
    }
  }
  /* release key */
  RELEASE_KEYS(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) { // print usage
    fputs("Usage: piz_hid-keyboard <layout>\n", stderr);
    exit(1);
  }
  if (!isdigit(argv[1][0])) { // must either 0 or 1
    fputs("Layout must be a digit\n", stderr);
    exit(1);
  }
  int lay = atoi(argv[1]);

  FILE *fp;
  if ((fp = fopen("/dev/hidg0", "w")) == NULL) { // open device
    fputs("Couldn't open /dev/hidg0 device\n", stderr);
    exit(1);
  }

  int c;
  while ((c = getc(stdin)) != EOF) {
    write_key(&layout[c].keys[lay], fp);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
