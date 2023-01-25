#include <iostream>
#include <cstring>
using namespace std;

int space_search(char * _line, int _n) {
	int _space = 0, checker = 0;
	for (int i = 0; i < _n; i++) {
		if (_line[i] == '.')
			checker++;
		else
			checker = 0;
		if (checker == 2)
			_space++;
	}
	return _space;	
}

int main(void) {
	int N, row_space = 0, col_space = 0;
	cin >> N;
	char ** map = new char*[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new char[N + 1];
		memset(map[i], '\0', sizeof(char) * (N + 1));
	}
	char * line = new char[N + 1];
	memset(line, '\0', sizeof(char) * (N + 1));
	for (int i = 0; i < N; i++) 
		cin >> map[i];
	
	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= N; k++) {
			line[k] = map[k][i];
		}
		col_space += space_search(map[i], N);
		row_space += space_search(line, N);

	}
	cout << col_space << " " <<  row_space;
	return 0;
}
