/* takes a password, a salt string and an optional number of iterations
 * (1000000 by default) and returns an hash of the password using
 * PKCS5_PBKDF2_HMAC SHA3-512
 */

/* compile with gcc piz_hid-hash.c -lssl -lcrypto */


#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE 700
#define KEY_LEN	64
#define SALT_LEN 64


int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "usage: piz_hid-crypt [-v] <password> <salt> [iterations]");
		exit(1);
	}
	OPENSSL_malloc_init();
	unsigned char *out, *salt;
	out = (unsigned char *) OPENSSL_secure_malloc(sizeof(unsigned char) * KEY_LEN);
	salt = (unsigned char *) OPENSSL_secure_malloc(sizeof(unsigned char) * SALT_LEN);
	unsigned int iter = 1000000;
	unsigned short int basei = 1;

	if (strcmp(argv[1], "-v") == 0) {
		/* verbose mode printf pass salt and iteration */
		basei = 2;

		printf("pass: %s\n", argv[basei]);

		printf("salt: ");
		for (size_t i = 0; i < SALT_LEN; i++) {
			salt[i] = argv[3][i];
			printf("%02x", salt[i]);
		}
		printf("\n");

		if (argc == 5)
			iter = atoi(argv[4]);
		printf("iter: %d\n", iter);

	}
	else {
		for (size_t i = 0; i < SALT_LEN; i++)
			salt[i] = argv[2][i];

		if (argc == 4)
			iter = atof(argv[3]);

	}

	/* algorythm is defined by EVP_sha3_512 */
	if (PKCS5_PBKDF2_HMAC(argv[basei], strlen(argv[basei]), salt, SALT_LEN, iter, EVP_sha3_512(), KEY_LEN, out) != 0) {
		for (size_t i = 0; i < KEY_LEN; i++){
			printf("%02x", out[i]);
		}
		puts("");
	}
	else {
		fprintf(stderr, "PKCS5_PBKDF2_HMAC failed\n");
		exit(1);
	}

	OPENSSL_secure_free(salt);
	OPENSSL_secure_free(out);

	return 0;
}
