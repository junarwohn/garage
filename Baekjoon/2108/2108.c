#include <stdio.h>
#include <stdlib.h>

void quick_sort(int * arr_, int s_, int e_) {
	int pivot_val = arr_[(s_ + e_) / 2];
	int i_l = s_, i_r = e_;
	do {
		while (arr_[i_l] < pivot_val)
			i_l++;
		while (pivot_val < arr_[i_r])
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

int main()
{
	int N = 0;
	scanf("%d", &N);
	int * arr = (int *)malloc(sizeof(int) * N);
	//FILE *fp;
	//int num;
	//int x = 0;
	//if (fp = fopen("data__.txt", "r"))
	//{
	//	while (0 < fscanf(fp, "%d", arr + x++));
	//	fclose(fp);
	//}
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	quick_sort(arr, 0, N - 1);
	//printf("%d\n", arr[0]);
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	int mean = (sum > 0 ? (((long double)sum / N) * 10 + 5) / 10 : (((long double)sum / N) * 10 - 5) / 10);
	int mid = arr[N / 2];
	int * freq_list = (int *)malloc(sizeof(int) * (arr[N - 1] - arr[0] + 1));

	for (int i = 0; i < arr[N - 1] - arr[0] + 1; i++)
		freq_list[i] = 0;

	for (int i = 0; i < N; i++)
		freq_list[arr[i] - arr[0]]++;

	int max = freq_list[0];
	int max_freq_index = -1;

	for (int i = 0; i < arr[N - 1] - arr[0] + 1; i++) {
		if (max < freq_list[i])
			max = freq_list[i];
	}

	for (int i = 0; i < arr[N - 1] - arr[0] + 1; i++) {
		if (freq_list[i] == max) {
			if (max_freq_index == -1) {
				max_freq_index = i;
			}
			else {
				max_freq_index = i;
				break;
			}
		}
	}

	printf("%d\n", (int)mean);
	printf("%d\n", mid);
	printf("%d\n", max_freq_index + arr[0]);
	printf("%d\n", arr[N - 1] - arr[0]);
	free(arr);
	free(freq_list);
	return 0;
}
