#include <stdio.h>
#include <stdlib.h>

void merge_sort(int * list_, int s_, int e_){
    if (e_ - s_ > 0) {
        int s_1 = s_, e_1 = (s_ + e_) / 2, s_2 = (s_ + e_) / 2 + 1, e_2 = e_;
        
        merge_sort(list_, s_1, e_1);
        merge_sort(list_, s_2, e_2);
        
        int merged_s = s_, merged_e = e_;
        int * merged_list = (int *)malloc(sizeof(int) * (merged_e - merged_s + 1));
        
        int merged_list_index = 0;
        for (; s_1 <= e_1 && s_2 <= e_2; merged_list_index++){
            merged_list[merged_list_index] = (list_[s_1] < list_[s_2]) ? list_[s_1++] : list_[s_2++];
        }
            
        for (;s_2 <= e_2; s_2++) 
            merged_list[merged_list_index++] = list_[s_2];
        for (;s_1 <= e_1; s_1++) 
            merged_list[merged_list_index++] = list_[s_1];

                
        for (int i = 0; i <= merged_e - merged_s; i++)
            list_[merged_s + i] = merged_list[i];
        free(merged_list);
    }
}

int main(void) {
    int N = 0;
    scanf("%d", &N);
    int * list = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) 
        scanf("%d", list + i);
    merge_sort(list, 0,  N - 1);
    for (int i = 0; i < N; i++)
        printf("%d\n", list[i]);
    return 0;
}
