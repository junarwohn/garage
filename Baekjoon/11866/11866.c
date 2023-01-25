#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
	struct node * previous;
};

typedef struct node * Node;

Node HEAD = NULL;
Node TOP = NULL;
void push(int value_) {
	if(!HEAD) {
		HEAD = (Node)malloc(sizeof(struct node));
		TOP = HEAD;
		TOP->value = value_;
		TOP->next = TOP;
		TOP->previous = TOP;
	} else {
		Node next_node = TOP->next;
		TOP->next = (Node)malloc(sizeof(struct node));
		TOP->next->value = value_;
		TOP->next->previous = TOP;
		TOP->next->next = next_node;
		next_node->previous = TOP->next;
		TOP = TOP->next;
	}
}


int pop() {
	int result = TOP->value;
	if (!(TOP->next)) {
		free(TOP);
	} else {
		Node tmp = TOP->next;
		TOP->previous->next = TOP->next;
		TOP->next->previous = TOP->previous;
		free(TOP);
		TOP = tmp;
	}
	return result;
}

void move(int mv_) {
    for (int i = 0; i < mv_ - 1; i++) {
        TOP = TOP->next;
    }
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        push(i);
    }
	for (int i = 0; i < N; i++) {
		HEAD = HEAD->next;
	}
    int * jsps_list = (int *)malloc(sizeof(int) * N);
    TOP = HEAD;
    for (int i = 0; i < N; i++) {
        move(M);
        jsps_list[i] = pop();
    }
    printf("<");
    for (int i = 0; i < N - 1; i++) {
        printf("%d, ", jsps_list[i]);
    }
    printf("%d>\n", jsps_list[N - 1]);
    return 0;
}
