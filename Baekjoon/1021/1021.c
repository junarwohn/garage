#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node * next;
	struct node * previous;
};

typedef struct node * Node;

Node FRONT = NULL;
Node ITOR_NODE = NULL

void push(int _x) {
	if (!FRONT) {
		FRONT = (Node)malloc(sizeof(struct node));
		ITOR_NODE = FRONT; 
		ITOR_NODE->value = _x;
		ITOR_NODE->next = ITOR_NODE->previous = ITOR_NODE;
	} else {
		ITOR_NODE->next = (Node)malloc(sizeof(struct node));
		ITOR_NODE->next->previous = ITOR_NODE;
		ITOR_NODE = ITOR_NODE->next;
		ITOR_NODE->next = HEAD;
		ITOR_NODE->value = _x;
		HEAD->previous = ITOR_NODE;
	}
}

void pop(Node _itor) {
	if (_itor == _itor->next) {
		free(_itor); FRONT = ITOR_NODE = NULL;
	} else {
		Node tmp = _itor->previous;
		tmp->next = _itor->next;
		_itor->next->previous = tmp;
		free(_itor);
	}
}
void initial_deque() {
	ITOR_NODE = FRONT;
}

int search

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		push(i);
	}
	initial_deque();

}
