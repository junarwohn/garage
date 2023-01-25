#include <iostream>

using namespace std;

void swap(int * list, int l, int r) {
	int tmp = list[l];
	list[l] = list[r];
	list[r] = tmp;
}

void sort(int * list, int left, int right) {
	int low = left;
	int high = right;
	int pivot = list[(left + right) / 2];
	do {
		while (list[low] < pivot) low++;
		while (list[high] > pivot) high--;
		if (low <= high) swap(list, low++, high--);
	} while (low <= high);
	if (left < high) sort(list, left, high);
	if (low < right) sort(list, low, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	int * input_list = new int[q];
	for (int i = 0; i < q; i++) cin >> input_list[i];
	sort(input_list, 0, q - 1);
	cout << input_list[q / 2] << '\n';
	return 0;
}
