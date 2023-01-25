#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};

typedef struct node * Node;

int str_cmp(const char * word_a, int a_word_len, char * word_b) {
	char is_equal = 1;
	for (int i = 0; i < a_word_len; i++) {
		if (word_a[i] != word_b[i]) {
			is_equal = 0;
			break;
		}
	}
	return is_equal;
}

int main(void) {
	Node HEAD = (Node)malloc(sizeof(struct node));
	Node Itor = (Node)malloc(sizeof(struct node));
	// Node TAIL = (Node)malloc(sizeof(struct node));
	HEAD->next = NULL;
	HEAD->value = -1;
	int N = 0;
	scanf("%d", &N);
	char cmd[20];
	getchar();
	for (int i = 0; i < N; i++) {
		fgets(cmd, sizeof(cmd), stdin);
		if (str_cmp("push", 4, cmd)) {
			int val = 0;
			int index = 5;
			while (*(cmd + index) != '\n') {
				val *= 10;
				val += *(cmd + index) - '0';
				index++;
			}
			Itor = HEAD;
			while (Itor->next)
				Itor = Itor->next;
			Itor->next = (Node)malloc(sizeof(struct node));
			Itor->next->value = val;
			Itor->next->next = NULL;
		}
		else if (str_cmp("pop", 3, cmd)) {
			if (!HEAD->next) {
				printf("-1\n");
			}
			else {
				// Itor = HEAD->next->next;
				Itor = HEAD;
				while (Itor->next->next)
					Itor = Itor->next;
				// printf("%d\n", HEAD->next->value);
				printf("%d\n", Itor->next->value);
				free(Itor->next);
				Itor->next = NULL;
				// HEAD->next = Itor;
			}
		}
		else if (str_cmp("size", 4, cmd)) {
			int size_ = 0;
			Itor = HEAD;
			while (Itor->next) {
				size_++;
				Itor = Itor->next;
			}
			printf("%d\n", size_);
		}
		else if (str_cmp("empty", 5, cmd)) {
			if (HEAD->next) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}
		else if (str_cmp("top", 3, cmd)) {
			if (HEAD->next) {
				Itor = HEAD;
				while (Itor->next)
					Itor = Itor->next;
				printf("%d\n", Itor->value);
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}