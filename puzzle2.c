#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ct[30] = "\xbf\xb5\xb8\xbe\xa2\xe9\xb7\xea\x86\xad\xe8\xb4\xea\x86\xea\xb7\xba\xab\xee\xa9\xad\xb0\xe9\xb7\x86\xe9\xb7\xe8\xa0\xa4";

int check(char *password) {
	size_t len = strlen(password);
	for (int i = 0; i < len; ++i) {
		password[i] = password[i] ^ 0xd9;
	}

	return memcmp(ct, password, len);
}

int main(void) {
	char *buf = malloc(0x100);
	if (!buf) {
		perror("Malloc");
		return 1;
	}

	printf("Enter password: ");
	scanf("%255s", buf);

	if (check(buf)) {
		puts("Wrong.");
	} else {
		puts("Correct!");
	}

	free(buf);

	return 0;
}