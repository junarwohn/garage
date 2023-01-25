#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do {
		while (arr[i] < pivot)
	  	    i++;
	  	while (arr[j] > pivot)
	  	    j--;
	  	if (i<= j)
	  	{
	  	    temp = arr[i];
	  	    arr[i] = arr[j];
	  	    arr[j] = temp;
	  	    i++;
	  	    j--;
	  	}
	} while (i<= j);

    /* recursion */
    if (left < j)
    	quickSort(arr, left, j);

    if (i < right)
        quickSort(arr, i, right);
}

int main(void) {
	int height_list[9] = {0,};
	int sum_of_height = 0, delta;
	for (int i = 0; i < 9; i++) {
		cin >> height_list[i];
		sum_of_height += height_list[i];
	}
	delta = sum_of_height - 100;
	quickSort(height_list, 0, 8);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int candi = height_list[i] + height_list[j];
			if (candi == delta) {
				height_list[i] = -1;
				height_list[j] = -1;
				for (int k = 0; k < 9; k++) {
					if (height_list[k] == -1) 
						continue;
					else
						cout << height_list[k] << '\n';
				}
				return 0;
			}
			if (candi > delta)
				continue;
		}
	}
	return 0;
}
