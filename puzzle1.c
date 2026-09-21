#include <stdio.h>
#include <string.h>

int check(char *pass) {
	char data[50];
	strcpy(data, "flag{");
	strcat(data, "s3cr3t_5");
	strcat(data, "tuff_h3");
	strcat(data, "r3}");
	return strcmp(pass, data);
}

int main(void) {
	char input[50];
	
	printf("Enter password: ");
	scanf("%49s", input);
	if (check(input)) {
		printf("Wrong.\n");
	} else {
		printf("Correct!\n");
	}

	return 0;
}