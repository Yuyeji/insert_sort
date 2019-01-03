#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	char *s_num;
	struct node *next;
}Node;

int main(void) {
	int size = 0;
	struct node temp;
	FILE* f;
	struct node num[100];
	int i = 0, j;

	f = fopen("test_10.txt", "r");

	if (f == NULL) {
		printf("파일이 열리지 않습니다.");
		exit(1);
	}

	while (feof(f) == 0) {
		size++;
		fscanf(f, "%d", &(num[i].number));
		i++;
	}
	for (int k = 0; k < size; k++) {
		for (i = 1; i < size; i++) {
			for (j = 0; j < i; j++) {
				if (num[i].number < num[j].number) {
					temp = num[i];
					num[i] = num[j];
					num[j] = temp;
					break;
				}
			}
		}
	}
	for (i = 0; i< size; i++) {
		printf("%d\n", num[i].number);
	}
	fclose(f);
}