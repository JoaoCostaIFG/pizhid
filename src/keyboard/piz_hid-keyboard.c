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
#include <time.h>

#include "keys.h"

#define _XOPEN_SOURCE 700
#define MILISEC       1000
#define NANOSEC       1000000

#define INSERT_KEY(dev, mod, chr) \
  fprintf(dev, "%c%c%c%c%c%c%c%c", mod, '\0', chr, '\0', '\0', '\0', '\0', '\0')

void
sleep_ms(int milliseconds)
{
  /* pause execution for milliseconds ms */
  struct timespec ts;
  ts.tv_sec  = milliseconds / MILISEC;
  ts.tv_nsec = (milliseconds % MILISEC) * NANOSEC;
  nanosleep(&ts, NULL);
}

void
release_keys(FILE* fp)
{
  INSERT_KEY(fp, '\0', '\0');
}

void
write_key(struct Key* key, FILE* fp)
{
  /* press key */
  INSERT_KEY(fp, key->modifier, key->chr);
  /* dead keys need to be pressed twice */
  if (key->is_dead) {
    release_keys(fp);
    INSERT_KEY(fp, key->modifier, key->chr);
  }
  /* release key */
  release_keys(fp);
}

int
main(int argc, char* argv[])
{
  // print usage
  if (argc < 3) {
    fputs("Usage: piz_hid-keyboard <layout> <text>\n", stderr);
    exit(1);
  }
  if (!isdigit(argv[1][0])) {
    fputs("Layout must be a digit\n", stderr);
    exit(1);
  }
  int lay = atoi(argv[1]); // get layout number

  // open device
  FILE* fp;
  if ((fp = fopen("/dev/hidg0", "w")) == NULL) {
    fputs("Couldn't open /dev/hidg0 device\n", stderr);
    exit(1);
  }

  for (int i = 2; i < argc; ++i) {
    for (int j = 0; j < strlen(argv[i]); ++j) {
      write_key(&layout[(int)argv[i][j]].keys[lay], fp);
    }

    if (i < argc - 1) // insert white space between words
      write_key(&layout[(int)' '].keys[lay], fp);
  }

  fclose(fp);
  return 0;
}
