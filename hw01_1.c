#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	long long int *s_num;
	int score;
	struct node *next;
}Node;

int main(void) {
	int size = 0;
	struct node temp;
	FILE* f;
	struct node num[50];
	int i = 0, j;

	f = fopen("test1.txt", "r");

	if (f == NULL) {
		printf("파일이 열리지 않습니다.");
		exit(1);
	}

	while (feof(f) == 0) {
		size++;
		fscanf(f, "%lld %d", &(num[i].s_num), &(num[i].score));
		i++;
	}
	for (int k = 0; k < size; k++) {
		for (i = 1; i < size; i++) {
			for (j = 0; j < i; j++) {
				if (num[i].score < num[j].score) {
					temp = num[i];
					num[i] = num[j];
					num[j] = temp;
					break;
				}
			}
		}
	}
	for (i = 0; i < size - 1; i++) {
		printf("%d   %d \n", num[i].s_num, num[i].score);
	}
	fclose(f);
}