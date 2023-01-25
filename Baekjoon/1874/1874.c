#include <stdio.h>
#include <stdlib.h>

int * push_pop_list;
int push_pop_list_index = 0;
int N = 0;
struct node {
	int value;
	struct node * next;
};

typedef struct node * Node;

void push(Node *Stack_TOP, int val) {
	(*Stack_TOP)->next = (Node)malloc(sizeof(struct node));
	(*Stack_TOP)->next->value = val;
	(*Stack_TOP)->next->next = NULL;
	(*Stack_TOP) = (*Stack_TOP)->next;
	push_pop_list[push_pop_list_index++]++;
}

void pop(Node Stack_HEAD, Node *Stack_TOP) {
	Node Itor_ = Stack_HEAD;
	while (Itor_->next != *Stack_TOP)
		Itor_ = Itor_->next;
	*Stack_TOP = Itor_;
	free(Itor_->next);
	(*Stack_TOP)->next = NULL;
	push_pop_list[push_pop_list_index++]--;
}

int get_stack_num() {
	int num = 0;
	for (int i = 0; push_pop_list[i] != 0; i++) {
		if (push_pop_list[i] == 1) 
			num++;
	}
	return num;
}

int main(void) {
	int N = 0;
	Node HEAD = (Node)malloc(sizeof(struct node));
	Node TOP = HEAD;
	HEAD->next = NULL;
	HEAD->value = -1;
	scanf("%d", &N);
	int input = 0;
	Node Itor = NULL;
	push_pop_list = (int *)malloc(sizeof(int) * (2 * N));
	for (int i = 0; i < 2 * N; i++)
		push_pop_list[i] = 0;
	for (int k = 0; k < N; k++) {
		scanf("%d", &input);
		
		if (!HEAD->next) {
			for (int i = (push_pop_list_index) / 2 + 1; i <= input; i++)
				push(&TOP, i);
			pop(HEAD, &TOP);
		}
		else {
			Itor = HEAD;
			while (Itor->next)
				Itor = Itor->next;

			if (Itor->value < input) {
				if (get_stack_num() >= input) {
					printf("-1\n");
					return 0;
				}
			for (int i = get_stack_num() + 1; i <= input; i++) {
					push(&TOP, i);
				}
				pop(HEAD, &TOP);
			}
			else if (Itor->value == input) {
				pop(HEAD, &TOP);
			}
			else {
				printf("NO\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < 2 * N; i++) {
		if (push_pop_list[i] == -1)
			printf("-\n");
		else
			printf("+\n");
	}
	return 0;
}
