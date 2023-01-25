#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	char input[201];
	char * iter = input;
	scanf("%s", input);
	while (*iter != '\0')
		printf("%d ", (int) (*(iter++) - 'A' + 1));
	return 0;
}
