#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

typedef struct node * Node;

int is_empty(Node HEAD_){
    return HEAD_->next ? 0 : 1;
}

Node end(Node HEAD_) {
    while (HEAD_->next)
        HEAD_ = HEAD_->next;
    return HEAD_;
}

void push(Node HEAD_, int value_) {
    Node end_ = end(HEAD_);
    end_->next = (Node)malloc(sizeof(struct node));
    end_->next->value = value_;
    end_->next->next = NULL;
}

void pop(Node HEAD_) {
    if (is_empty(HEAD_)) {
        printf("-1\n");
        return;
    } 
    printf("%d\n", HEAD_->next->value);
    Node itor_ = HEAD_->next;
    HEAD_->next = itor_->next;
    free(itor_);
}

int str_cmp(char * cmd_, const char * op_) {
    while (*cmd_ != '\0' && *op_ != '\0') {
        if (*op_ != *cmd_) {
            break;
        }
        cmd_++;
        op_++;
    }
    return *cmd_ - *op_;
}

int main(void) {
    Node HEAD = (Node)malloc(sizeof(struct node));
    HEAD->value = -1;
    HEAD->next = NULL;
    char cmd[10];
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", cmd);
        if (str_cmp(cmd, "push") == 0) {
            int x = 0;
            scanf("%d", &x);
            push(HEAD, x);
        } else if (str_cmp(cmd, "pop") == 0) {
            pop(HEAD);
        } else if (str_cmp(cmd, "size") == 0) {
            Node itor = HEAD;
            int size = 0;
            while (itor->next) {
                size++;
                itor = itor->next;
            }
            printf("%d\n", size);
        } else if (str_cmp(cmd, "empty") == 0) {
            printf("%d\n", is_empty(HEAD));
        } else if (str_cmp(cmd, "front") == 0) {
            if (!is_empty(HEAD)) {
                printf("%d\n", HEAD->next->value);
            } else {
                printf("-1\n");
            }
        } else if (str_cmp(cmd, "back") == 0) {
            if (!is_empty(HEAD)) {
                printf("%d\n", end(HEAD)->value);
            } else {
                printf("-1\n");
            }
        }
    }
}