/* Takes a password, a salt string and an optional number of iterations
 * (1000000 by default) and returns an hash of the password using
 * PKCS5_PBKDF2_HMAC with SHA3-512.
 * The given salt must be at least 64 byte long (only the first 64 bytes are
 * used). Smaller salt lengths will yield inconsistent results.
 */

/* compile with gcc piz_hid-hash.c -lssl -lcrypto */

#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE 700
#define HASH_LEN      64
#define SALT_LEN      64
#define DFLT_ITER     1000000
#define PASS_IND      1
#define SALT_IND      2
#define ITER_IND      3

int
main(int argc, char* argv[])
{
  if (argc < 3) {
    fputs("usage: piz_hid-crypt <password> <salt> [iterations]\n", stderr);
    exit(1);
  }

  /* memory allocation */
  OPENSSL_malloc_init();
  unsigned char* out =
    (unsigned char*)OPENSSL_secure_malloc(sizeof(unsigned char) * HASH_LEN);
  if (!out) {
    fputs("Memory allocation for hash failed. Exiting..", stderr);
    exit(1);
  }
  unsigned char* salt =
    (unsigned char*)OPENSSL_secure_malloc(sizeof(unsigned char) * SALT_LEN);
  if (!salt) {
    fputs("Memory allocation for salt failed. Exiting..", stderr);
    exit(1);
  }

  /* store salt */
  for (size_t i = 0; i < SALT_LEN; i++)
    salt[i] = argv[SALT_IND][i];

  /* set iteration number */
  int iter;
  if (argc > ITER_IND)
    iter = atoi(argv[ITER_IND]);
  else
    iter = DFLT_ITER;
  printf("%d\n", iter);

  /* algorythm is defined by EVP_sha3_512 */
  if (PKCS5_PBKDF2_HMAC(argv[PASS_IND],
                        strlen(argv[PASS_IND]),
                        salt,
                        SALT_LEN,
                        iter,
                        EVP_sha3_512(),
                        HASH_LEN,
                        out) != 0) {
    for (size_t i = 0; i < HASH_LEN; i++)
      printf("%02x", out[i]);
    puts("");
  }
  else {
    fputs("Hash calculation failed\n", stderr);
    exit(1);
  }

  /* free memory */
  OPENSSL_secure_free(salt);
  OPENSSL_secure_free(out);
  return 0;
}
