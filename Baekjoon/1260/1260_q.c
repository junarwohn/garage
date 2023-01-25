#include <stdio.h>
#include <stdlib.h>

int ** mtrx;
int * vst;
int * queue;
int queue_HEAD = 0;
int queue_TOP = 0;

void push(int val_) {
    queue[++queue_TOP] = val_;
}

int pop() {
    if (queue_HEAD == queue_TOP)
        return 0;
    else {
        printf("%d ", queue[queue_HEAD + 1]);
        return queue[++queue_HEAD];
    }
}        

void DFS(int val_, int N_) {
    push(val_);
    vst[val_] = 1;
    for (int i = 1; i <= N_; i++) {
        if (mtrx[val_][i] && !vst[i])
            DFS(i, N_);
    }
}

void BFS(int val_, int N_) {
    push(val_);
    vst[val_] = 1;
    int S_;
    while ((S_ = pop())) {
        for (int i = 1; i <= N_; i++) {
            if (mtrx[i][S_] && !vst[i]) {
                vst[i] = 1;
                push(i);
            }
        }
    }
}

int main(void) {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    mtrx = (int **)malloc(sizeof(int *) * (N + 1));
    vst = (int *)malloc(sizeof(int) * (N + 1));
    queue = (int *)malloc(sizeof(int) * (N + 1));

    for (int i = 1; i <= N; i++) {
        mtrx[i] = (int *)malloc(sizeof(int) * (N + 1));
        vst[i] = 0;
        queue[i] = 0;
        for (int j = 1; j <= N; j++) {
            mtrx[i][j] = 0;
        }
    }
    int x, y;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        mtrx[x][y] = mtrx[y][x] = 1;
    }
    DFS(V, N);
    while(pop());
    printf("\n");
    for (int i = 0; i <= N; i++) {
        vst[i] = 0;
    }
    queue_HEAD = 0;
    queue_TOP = 0;
    BFS(V, N);
    free(mtrx);
    free(vst);
    free(queue);
    return 0;
}