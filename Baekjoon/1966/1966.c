#include <stdio.h>
#include <stdlib.h>

struct node {
    int priority;
    int index;
    struct node * next;
};

typedef struct node * Node;
Node HEAD;
Node TOP;

void push(int index_, int priority_) {
    if (!HEAD)
        HEAD = TOP = (Node)malloc(sizeof(struct node));
    else {
        TOP->next = (Node)malloc(sizeof(struct node));
        TOP = TOP->next;
    }
    TOP->priority = priority_;
    TOP->index = index_;
    TOP->next = NULL;
    //printf("push %d\n", index_);
}

int pop() {
    if (!HEAD) {
        //printf("pop error\n");
        return -1;
    } else {
        Node tmp = HEAD;
        HEAD = HEAD->next;
        int index = tmp->index;
        free(tmp);
        //printf("%d\n", index);
        return index;
    }
}

int max_p() {
    Node itor = HEAD;
    int max_p_ = itor->priority;
    while (itor) {
        if (max_p_ < itor->priority)
            max_p_ = itor->priority;
        itor = itor->next;
    }
    return max_p_;
}

void print_queue(int index_) {
    int cnt = 0;
    int max_, curr_p;
    while(HEAD) {
        //printf("print queue\n");
        max_ = max_p();
        //printf("max %d\n", max_);
        curr_p = HEAD->priority;
        if (max_ != curr_p) {
            push(pop(), curr_p);
        } else {
            cnt++;
            int index = pop();
            //printf("index :: %d\n", index);
            if (index == index_) {
                printf("%d\n", cnt);
                break;
            }
        }
    }
}

int main(void) {
    HEAD = TOP = NULL;
    int T, N, M;
    scanf("%d", &T);
    for (int i_ = 0; i_ < T; i_++) {
        scanf("%d %d", &N, &M);
        int p = 0;
        for (int index_ = 0; index_ < N; index_++) {
            scanf("%d", &p);
            push(index_, p);
        }
        print_queue(M);
        while(pop() != -1);
    }
    while(pop() != -1);
    return 0;
}