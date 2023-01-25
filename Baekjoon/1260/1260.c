#include <stdio.h>
#include <stdlib.h>

int * visit;

void DFS(char ** matrix_, int N_, int v_) {
    printf("%d ", v_);
    visit[v_]++;
    for (int i = 1; i <= N_; i++) {
        if (matrix_[v_][i]) {
            if (!visit[i]) {
                DFS(matrix_, N_, i);
            }
        }
    }
}


void BFS(char ** matrix_, int N_, int v_) {
    visit[v_] = 1;
    for (int i = 1; i <= N_; i++) {
        if ((matrix_[v_][i] == 1) && (visit[i] == 0)) {
            visit[i] = -1;
            printf("%d ", i);
        }
    }
    for (int i = 1; i <= N_; i++) {
        if (matrix_[v_][i]) {
            if (visit[i] == -1){
                visit[i] = 1;
                BFS(matrix_, N_, i);
            }
        }
    }
}

int main(void) {
    int N = 0;
    scanf("%d", &N);
    char ** matrix = (char **)malloc(sizeof(char *) * (N + 1));
    for (int i = 0; i <= N; i++) {
        matrix[i] = (char *)malloc(sizeof(char) * (N + 1));
        for (int j = 0; j <= N; j++)
            matrix[i][j] = 0;
    }
    visit = (int *)malloc(sizeof(int) * (N + 1));

    int M = 0;
    scanf("%d", &M);
    int V = 0;
    scanf("%d", &V);
    int x, y;
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &x, &y);
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    for (int i = 0; i <= N; i++)
        visit[i] = 0;
    DFS(matrix, N, V);
    printf("\n");
    for (int i = 0; i <= N; i++)
        visit[i] = 0;
    printf("%d ", V);
    BFS(matrix, N, V);
    printf("\n");
    return 0;
}