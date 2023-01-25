#include <stdio.h>
#include <stdlib.h>
int main(void) {
		int N = 0;
		scanf("%d", &N);
		int * input_list = (int *) malloc(sizeof(int) * N);
		char * is_checked = (char *) malloc(sizeof(char) * N);
		for (int  i = 0; i < N; i++ ){
				scanf("%d", input_list +i);
				is_checked[i] = 0;
		}
		char is_all_checked = 0;
		int max = 0;
		while (!is_all_checked) {
				int index = 0;
				int last = 0, sum = 0;
				while (is_checked[index] != 1) {
						index++;
				}
				if (index == N) {
						is_all_checked = 1;
						continue;
				} else {
						last 
						for (int i = index; i < N; i++) {
								if (!is_checked[i] &&  
				
