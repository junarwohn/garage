#include <iostream>

using namespace std;

int main(void) {
	// 1. 5개 정수 입력 후 합 출력 프로그램.
	cout << " 1. 5개 정수 입력 후 합 출력 프로그램." << "\n\n";
	int result = 0;
	int tmp = 0;
	for (int i = 1; i <= 5; i++) 
	{
		cout << i << "번째 정수 입력: ";
		cin >> tmp;
		result += tmp;
	}
	cout << "합계 : " << result << "\n\n";
	
	// 2. 이름, 전화번호 문자열
	cout << " 2. 이름, 전화번호 문자열" << "\n\n";
	char name[100];
	char phoneNum[100];
	cout << "이름 : ";
	cin >> name;
	cout << "전화번호 : ";
	cin >> phoneNum;
	cout << "이름 : " << name << "\n전화번호 : " << phoneNum << "\n\n";
	
	// 3. 구구단
	cout << " 3. 구구단" << "\n\n";
	int stage = 0;
	cout << "단을 입력하세요" << "\n";
	cin >> stage;
	for (int i = 1; i < 10; i++)
		cout << stage << " X " << i << " = " << stage * i << "\n";
	
	// 4. 급여 계산 프로그램. 50만원 기본급여에 판매가격의 12%를 더 받음.
	cout << "\n 4. 급여 계산 프로그램. 50만원 기본급여에 판매가격의 12%를 더 받음." << "\n\n";
	float sale_performance = 0;	

	while (true) 
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> sale_performance;
		if(sale_performance == -1)
			break;
		cout << "이번 달 급여: " << sale_performance * 0.12 + 50 << "만원\n";
	}
	cout << "프로그램을 종료합니다.";
	
	return 0;
}
