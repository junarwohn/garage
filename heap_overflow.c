#include <stdio.h>

typedef struct chunk {
    char inp[64];
    void (*process) (char *);
} chunk_t;

void showlen(char * buf) {
    int len;
    len = strlen(buf);
    printf("buffers read %d chars\n", len);
}

int main(int argc, char *argv[]) {
    chunk_t *next;
    setbuf(stdin, NULL);
    next = malloc(sizeof(chunk_t));
    next->process = showlen;
    printf("Enter value: ");
    gets(next->inp);
    next->process(next->inp);
    printf("Buffer 5 done\n");
    return 0;

}
