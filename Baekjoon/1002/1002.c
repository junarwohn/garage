#include <stdio.h>
#include <math.h>
long double len(double x1, double x2, double y1, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main(void) {
	int inputNum = 0;
	scanf("%d", &inputNum); 
	for (int i = 0; i < inputNum; i++) {
		int nums[6];
		for (int j = 0; j < 6; j++) {
			scanf("%d", &nums[j]);
		}
		if (nums[0] == nums[3] && nums[1] == nums[4]) {
			if (nums[2] == nums[5]) {
				printf("-1\n");
			} else {
				printf("0\n");
			}
		} else {
			long double length_ = len(nums[0], nums[3], nums[1], nums[4]);
			long double l[3];
			l[0] = length_;
			l[1] = nums[2];
			l[2] = nums[5];
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (l[i] < l[j]) {
							int tmp = l[j];
							l[j] = l[i];
							l[i] = tmp;
					}
				}
			}
			if (l[1] + l[2] > l[0]) {
				printf("2\n");
			} else if (l[1] + l[2] == l[0]){
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
			
