#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	char head_line[81];
	char * iter = head_line;
	cin >> head_line;
	while (*iter != '\0')
		if (*iter >= 'a' && *iter <= 'z')
			printf("%c", *(iter++) - 'a' + 'A');
		else
			printf("%c", *(iter++));
	return 0;
}
