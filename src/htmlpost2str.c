/*
 * When handling an html sumbmissions (either GET or POST), the information
 * comes in the form key1=info1&key2=info2...keyn=infon. Special chars
 * (e.g.: =, %, ,) come in hex format %HH where HH is the char hex code.
 *
 * the <key> part is optional. The '=' at the beginning of the string is still
 * mandatory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE 700
#define STR_MAX_SIZE 100

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Usage: htmlpost2str [key]=<info>\n");
    exit(1);
  }

  int found_eq;
  char *token, info[STR_MAX_SIZE], tmp_str[3];
  size_t i, j;

  tmp_str[2] = 0; // tmp_str is always 2 digits wide
  token = strtok(argv[1], "&");

  while (token) {
    // skip key name
    found_eq = 0;
    for (j = 0; j < strlen(token); ++j) {
      if (token[j] == '=') {
        ++j;
        found_eq = 1;
        break;
      }
    }
    if (!found_eq) {
      fprintf(stderr, "Error! No \'=\' sign found for the key:%s\n", token);
      exit(1);
    }

    // save and parse key info to output
    for (i = 0; j < strlen(token) && i < STR_MAX_SIZE; ++i, ++j) {
      if (token[j] == '%') {
        // convert 2 digit hex number to ascii
        tmp_str[0] = token[++j];
        tmp_str[1] = token[++j];

        info[i] = (char)strtol(tmp_str, NULL, 16);
      } else {
        info[i] = token[j];
      }
    }
    // output parsed key info
    info[i] = 0;
    puts(info);

    // get next key
    token = strtok(NULL, "&");
  }

  return 0;
}
