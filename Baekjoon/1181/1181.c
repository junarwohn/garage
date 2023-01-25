#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int str_len(char * word_) {
	int len_ = 0;
	while (*word_) {
		len_++; word_++;
	}
	return len_;
}

int str_cmp(char * word_a, char * word_b) {
	int len_a = str_len(word_a);
	int len_b = str_len(word_b);
	if (len_a > len_b) {
		return 1;
	} else if (len_a < len_b) {
		return 0;
	} else {
		int small_word = -1;
		for (int index = 0; index < len_a; index++) {
			if (word_a[index] > word_b[index]) {
				small_word = 1;
				break;
			} else if (word_a[index] < word_b[index]){
				small_word = 0;
				break;
			}
		}
		return small_word;
	}
	
}

void quick_word_sort(int * word_sort_index_list_, char ** word_list_, int s_, int e_) {
	int pivot_word_len = str_len(word_list_[word_sort_index_list_[(s_ + e_) / 2]]);
	char * pivot_val = (char*)malloc(sizeof(char) * pivot_word_len+ 1);
	for (int i = 0; i < pivot_word_len; i++)
		pivot_val[i] = word_list_[word_sort_index_list_[(s_ + e_) / 2]][i];
	pivot_val[pivot_word_len] = '\0';
	int i_l = s_, i_r = e_;
	do {
		// while (arr_[i_l] < pivot_val)
		while (str_cmp(word_list_[word_sort_index_list_[i_l]], pivot_val) == 0)
			i_l++;
		// while (pivot_val < arr_[i_r])
		while (str_cmp(pivot_val, word_list_[word_sort_index_list_[i_r]]) == 0)
			i_r--;

		if (i_l <= i_r) {
			int swap = word_sort_index_list_[i_l];
			word_sort_index_list_[i_l++] = word_sort_index_list_[i_r];
			word_sort_index_list_[i_r--] = swap;
		}
	} while (i_l <= i_r);
	free(pivot_val);
	//for (int i = 0; i < 13; i++) {
	//	printf("%s ", word_list_[word_sort_index_list_[i]]);
	//}
	//printf("\n");
	if (s_ < i_r)
		quick_word_sort(word_sort_index_list_, word_list_, s_, i_r);
	if (i_l < e_)
		quick_word_sort(word_sort_index_list_, word_list_, i_l, e_);
}

int main(void) {
	int N = 0;
	scanf("%d", &N);
	char ** word_list = (char **)malloc(sizeof(char *) * N);
	int * sort_index_list = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		word_list[i] = (char*)malloc(sizeof(char) * 51);
		sort_index_list[i] = i;
		scanf("%s", word_list[i]);
	}
	quick_word_sort(sort_index_list, word_list, 0, N - 1);
	for (int i = 0; i < N - 1; i++) {
		if (str_cmp(word_list[sort_index_list[i]], word_list[sort_index_list[i+1]]) == -1)
			continue;
		printf("%s\n", word_list[sort_index_list[i]]);
	}
	printf("%s\n", word_list[sort_index_list[N -1]]);
	return 0;
}