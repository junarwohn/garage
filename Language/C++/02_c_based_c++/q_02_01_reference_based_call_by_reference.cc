#include <iostream>

using namespace std;

void adder_reference(int &_input)
{
	_input++;
}

void change_sign_reference(int &_input)
{
	_input *= -1;
}

void swap_ptr(int *p1, int *p2) 
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}	

int main(void)
{
	// using reference, add 1 to a variable , change sign of variable
	int input_num = 0;
	cout << "using reference, add 1 to a variable , change sign of variable" << "\n";
	cout << "input number ";
	cin >> input_num;
	adder_reference(input_num);
	cout << "using reference, add 1 to input_num : " << input_num << "\n";
	change_sign_reference(input_num);
	cout << "using reference, change sign of input_num : " << input_num << "\n";
	
	// SwapByRef2(23, 45)
	// fuction call in this way cause error.
	// Because 23 and 45 is constant, so we cannot reference of constant.

	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	swap_ptr(ptr1, ptr2);
	cout << "num1 : " << num1 << ", num2 : " << num2 << "\n";
	return 0;
}
