#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dataBlock {
	size_t length;
	char *block;
	char key;
};

char ciphertext[34] = "\x01\x0b\x06\x00\x1c\x10\x57\x10\x38\x13\x0f\x53\x13\x52\x38\x06\x38\x0b\x57\x13\x38\x08\x01\x38\x14\x13\x15\x12\x04\x13\x12\x15\x54\x1a";

int check(struct dataBlock *password) {
	for (int i = 0; i < password->length; ++i) {
		if ((password->block[i] ^ password->key) != ciphertext[i])
			return 1;
	}
	return 0;
}

int main(void) {
	ssize_t ret;
	char *ptr;
	struct dataBlock *blk = (struct dataBlock *)malloc(sizeof(struct dataBlock));
	
	if (!blk) {
		perror("Malloc");
		return 1;
	}

	blk->length = 0;
	blk->block = NULL;
	blk->key = rand();

	printf("Enter password: ");
	ret = getline(&blk->block, &blk->length, stdin);
	if (ret == -1) {
		perror("Line read failure");
		if (blk->block)
			free(blk->block);
		free(blk);
		return 1;
	}

	ptr = strchr(blk->block, '\n');
	if (ptr)
		*ptr = '\0';
	blk->length = strlen(blk->block);

	if (check(blk)) {
		printf("Wrong.\n");
	} else {
		printf("Correct!\n");
	}

	free(blk->block);
	free(blk);

	return 0;
}