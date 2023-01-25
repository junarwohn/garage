#include <iostream>

using namespace std;

void swap(int * _num1, int * _num2) 
{
	int tmp = *_num1;
	*_num1 = *_num2;
	*_num2 = tmp;
}

void swap(char * _ch1, char * _ch2)
{
	char tmp = *_ch1;
	*_ch1 = *_ch2;
	*_ch2 = tmp;
}

void swap(double * _dbl1, double * _dbl2)
{
	double tmp = *_dbl1;
	*_dbl1 = *_dbl2;
	*_dbl2 = tmp;
}
int main(void) 
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << "\n";

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << " " << ch2 << "\n";
	
	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << " " << "\n";
	return 0;
}
