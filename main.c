#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 1024

void check_alloc(void* ptr) {
	if (ptr == NULL) {
		fprintf(stderr, "%s\n", "Not able to allocate pointer");
		exit(1);
	}
}

int main() {
	char tmp;
	int i = 0;
	char* buffer = (char*)malloc(DEFAULT_SIZE * sizeof(char));
	int current_size = DEFAULT_SIZE;

	check_alloc((char*)buffer);

	while ((tmp = getchar()) != EOF) {
		if (i > current_size) {
			current_size++;
			buffer = (char*)realloc(buffer, current_size);

			check_alloc((char*)buffer);
		}

		buffer[i] = tmp;
		i++;
	}

	for (; i >= 0; i--) {
		printf("%c", buffer[i]);
	}

	putc('\n', stdout);

	free(buffer);

	return 0;
}
