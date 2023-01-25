#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
	struct node * previous;
};

typedef struct node * Node;

Node HEAD = NULL;
Node TAIL = NULL;

void push_front(int _value) {
	if (!HEAD) {
		HEAD = (Node)malloc(sizeof(struct node));
		HEAD->next = NULL;
		TAIL = HEAD;
	} else {
		HEAD->previous = (Node)malloc(sizeof(struct node));
		HEAD->previous->next = HEAD;
		HEAD = HEAD->previous;
	}
	HEAD->previous = NULL;
	HEAD->value = _value;
}

void push_back(int _value) {
	if (!HEAD) {
		HEAD = (Node)malloc(sizeof(struct node));
		HEAD->next = NULL;
		TAIL = HEAD;
	} else {
		TAIL->next = (Node)malloc(sizeof(struct node));
		TAIL->next->previous = TAIL;
		TAIL = TAIL->next;
	}
	TAIL->next = NULL;
	TAIL->value = _value;
}

void pop_front() {
	if (!HEAD) {
		printf("-1\n"); 
	} else {
		printf("%d\n", HEAD->value);
		if (!(HEAD->next)) {
			free(HEAD);
			HEAD = NULL;
			TAIL = NULL;
		} else {
			HEAD = HEAD->next;
			free(HEAD->previous);
			HEAD->previous = NULL;
		}
	}
}

void pop_back() {
	if (!TAIL) {
		printf("-1\n"); 
	} else {
		printf("%d\n", TAIL->value);
		if (!(TAIL->previous)) {
			free(TAIL);
			HEAD = NULL;
			TAIL = NULL;
		} else {
			TAIL = TAIL->previous;
			free(TAIL->next);
			TAIL->next = NULL;
		}
	}
}

int size() {
	int cnt = 0;
	Node tmp = HEAD;
	while (tmp) {
		tmp = tmp->next;
		cnt++;
	}
	return cnt;
}

int is_empty() {
	if (HEAD)
		return 0;
	else 
		return 1;
}

void front() {
	if (HEAD) 
		printf("%d\n", HEAD->value);
	else 
		printf("-1\n");
}

void back() {
	if (TAIL)
		printf("%d\n", TAIL->value);
	else
		printf("-1\n");
}

int str_cmp(const char * word_1, char * word_2) {
	while (*word_1 && *word_2 && *word_1 == *word_2) {
		word_1++; word_2++;
	}
	return *word_1 - *word_2;
}
int main(void) {
	int N = 0;
	scanf("%d", &N);
	getchar();
	char cmd[20];
	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);
		if (str_cmp("push_back", cmd) == 0) {
			int x = 0;
			scanf("%d", &x);
			push_back(x);
		} else if (str_cmp("push_front", cmd) == 0) {
			int x = 0;
			scanf("%d", &x);
			push_front(x);
		} else if (str_cmp("pop_front", cmd) == 0) { 
			pop_front();
		} else if (str_cmp("pop_back", cmd) == 0) {
			pop_back();
		} else if (str_cmp("size", cmd) == 0) {
			printf("%d\n",size());
		} else if (str_cmp("empty", cmd) == 0) {
			printf("%d\n", is_empty());
		} else if (str_cmp("front", cmd) == 0) {
			front();
		} else if (str_cmp("back", cmd) == 0) {
			back();
		}
	}
	return 0;
}
