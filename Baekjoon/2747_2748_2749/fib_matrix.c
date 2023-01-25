#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
	long long int x_1_1;
	long long int x_1_2;
	long long int x_2_1;
	long long int x_2_2;
} matrix;

matrix DEFAULT_MATRIX = {1,1,1,0};

matrix matrix_multiply(matrix _mtrx_1, matrix _mtrx_2) {
	matrix result_mtrx = {0,0,0,0};
	result_mtrx.x_1_1 = (_mtrx_1.x_1_1 * _mtrx_2.x_1_1 + _mtrx_1.x_1_2 * _mtrx_2.x_2_1)%1000000;
	result_mtrx.x_2_1 = (_mtrx_1.x_2_1 * _mtrx_2.x_1_1 + _mtrx_1.x_2_2 * _mtrx_2.x_2_1)%1000000;
	result_mtrx.x_1_2 = (_mtrx_1.x_1_1 * _mtrx_2.x_1_2 + _mtrx_1.x_1_2 * _mtrx_2.x_2_2)%1000000;
	result_mtrx.x_2_2 = (_mtrx_1.x_2_1 * _mtrx_2.x_1_2 + _mtrx_1.x_2_2 * _mtrx_2.x_2_2)%1000000;
	return result_mtrx;
}

matrix matrix_pow(matrix _mtrx, long long int n) {
	if (n == 1) {
		return _mtrx;
	} else if (n == 2) {
		return matrix_multiply(_mtrx, _mtrx);
	} else {
		matrix tmp_mtrx = matrix_pow(_mtrx, n / 2);
		if (n % 2 == 1) {
			return matrix_multiply(matrix_multiply(tmp_mtrx, tmp_mtrx), DEFAULT_MATRIX);
		} else {
			return matrix_multiply(tmp_mtrx, tmp_mtrx);
		}
	}
}

int main(void) {
	matrix m_matrix = DEFAULT_MATRIX;
	long long int N = 0;
	scanf("%lld", &N);
	m_matrix = matrix_pow(m_matrix, N + 1);
	printf("%lld", m_matrix.x_2_2);
	return 0;
}
