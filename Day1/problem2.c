#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0


struct window {
    int val1;
    int val2;
    int val3;
};

// I just don't want to write these over and over
int sum_window(struct window *w) {
    return w->val1 + w->val2 + w->val3;
}

int window_cmp(struct window *left, struct window *right) {
    int diff = sum_window(left) - sum_window(right);
    return diff ? (diff > 0 ? -1 : 1) : 0;
}

// loads dst window with correct values
void change_windows(struct window *src, struct window *dest, int new_value) {
    dest->val1 = src->val2;
    dest->val2 = src->val3;
    dest->val3 = new_value;
}


char buffer[11];
int num_increases = 0;

int main() {
    struct window A;
    struct window B;
    int A_is_older = TRUE;

    // preload the first window
    if (fgets(buffer, 11, stdin) == NULL) goto end; //smiling imp emoji times 3
    A.val1 = atoi(buffer);
    if (fgets(buffer, 11, stdin) == NULL) goto end; //smiling imp emoji times 3
    A.val2 = atoi(buffer);
    if (fgets(buffer, 11, stdin) == NULL) goto end; //smiling imp emoji times 3
    A.val3 = atoi(buffer);


    while(1) {
	// Get value
	if (fgets(buffer, 11, stdin) == NULL) break;
	int current_value = atoi(buffer);
	
	if (A_is_older) {
	    change_windows(&A, &B, current_value);
	    num_increases += window_cmp(&A, &B) > 0 ? 1 : 0;
	} else {
	    change_windows(&B, &A, current_value);
	    num_increases += window_cmp(&B, &A) > 0 ? 1 : 0;
	}

	A_is_older = !A_is_older;

    }

end:
    printf("Number of increases: %d\n", num_increases);
    return 0;
}


















