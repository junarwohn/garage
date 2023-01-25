#include <stdio.h>
int length(char * str) {
    int a;
    for (a = 0; str[a] != '\0'; a++);
    return a;
}

int cmp (char * a, char *b, size_t n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i))
            return *a - *b;
    }
    return 0;
}

char *str(char *a, char *b) {
    int c = length(b);
    while(*a){
        if (cmp(a,b,c) == 0) 
            break;
        a++;
    }
    if (*a != '\0')
        return (char * )a;
    return NULL;
}

void swap(char *a, char *b, size_t n, size_t n_c) {
    int len_a = length(a);
    int len_b = length(b);
    int delta = len_b - n_c;
    for (int i = len_a + 1; i >= 0; i--) {
        a[i + delta] = a[i];
    }
    for (int i = 0; i < n; i ++) {
        char tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    }
}

int main(void) {
    char c[1000], d[1000], A[1000];
    char *e;
    scanf("%s",A);
    while(1){
        scanf("%s", c);
        if (c[0] == '0')
            break;
        scanf("%s", d);
        e = str(A,c);
        swap(e, d, length(d), length(c));
        printf("%s\n", A);
    }
    return 0;
}
