#include <stdio.h>
int fibonacci(int x, int arr[]){
     if(arr[2*x]!=-1 && arr[2*x+1]!=-1)
        return 0;
     if(x==0){
         arr[2*x]=1;
         arr[2*x+1]=0;
     }
     else if(x==1){
         arr[2*x]=0;
         arr[2*x+1]=1;
     }
     else{
         fibonacci(x-1, arr)+fibonacci(x-2, arr);
         arr[2*x]=arr[2*x-2]+arr[2*x-4];
         arr[2*x+1]=arr[2*x-1]+arr[2*x-3];
     }
}

int main(void){
    int fib_arr[90];
    int i;
    int n;
    int test_arr;
    for(i=0; i<90; i++){
        fib_arr[i] = -1;
    }
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &test_arr);
        fibonacci(test_arr,  fib_arr);
        printf("%d %d\n", fib_arr[2*test_arr], fib_arr[2*test_arr+1]);

    }
   return 0;
}
