#include <stdio.h>
#include <stdlib.h>

void quick_sort(int * arr_, int s_, int e_) {
	int pivot = arr_[(s_ + e_) / 2];
	int i_l = s_, i_r = e_;
	do {
		while (arr_[i_l] < pivot)
			i_l++;
		while (pivot < arr_[i_r])
			i_r--;
		if (i_l <= i_r) {
			int swap = arr_[i_l];
			arr_[i_l++] = arr_[i_r];
			arr_[i_r--] = swap;
		}
	} while (i_l <= i_r);
	if (s_ < i_r)
		quick_sort(arr_, s_, i_r);
	if (i_l < e_)
		quick_sort(arr_, i_l, e_);
}

int main(void) {
    long int N = 0;
    scanf("%ld", &N);
    int len = 1;
    long int len_check = N;
    while (len_check /= 10)
        len++;
    int * list = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        list[i] = N%10;
        N /= 10;
    }
    quick_sort(list, 0, len - 1);
    for (int i = len; i > 0; i--)
        printf("%d", list[i - 1]);
    return 0;
}
