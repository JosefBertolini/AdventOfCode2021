#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int previous_value = INT_MAX;
int num_increases = 0;

int main() {
    char buffer[11]; // 10 digits can fit in an int32 + null terminator
    while (1) {
	if (fgets(buffer, 11, stdin) == NULL) break;
	int current_value = atoi(buffer);
	num_increases += current_value > previous_value ? 1 : 0;
	previous_value = current_value;
    }

    printf("Number of increases: %d\n", num_increases);
}
