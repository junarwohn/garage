#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node * pNode;
typedef pNode List;
typedef pNode Node;

struct node{
   int value;
   Node next;
};
int p;
List makeEmptyList(List L);
void insert_n(int v, List L, Node N);
void delete_n(int v, List L);
Node findPrev(int v, List L);
Node find(int v, List L);
void deleteList(List L);
void showList(List L);

int main() {
   List member;
   member = NULL;
   char input[20];
   char *pinput;
   makeEmptyList(member);
   

   while (1) {
      gets(input);
      pinput = strtok(input, " ");
      if (strcmp(pinput, "i") == 0) {

      }
      else if (strcmp(pinput, "d") == 0) {

      }
      else if (strcmp(pinput, "f") == 0) {

      }
      else if (strcmp(pinput, "s") == 0) {
      
      }
      else if (strcmp(pinput, "e") == 0) {
         printf("Exit Program\n");
         break;
      }
   }
   return 0;
}


List makeEmptyList(List L) {      
   L->next = NULL;
   return L;
}