#include <iostream>

using namespace std;

int main(void) {
	// 1. 5�� ���� �Է� �� �� ��� ���α׷�.
	cout << " 1. 5�� ���� �Է� �� �� ��� ���α׷�." << "\n\n";
	int result = 0;
	int tmp = 0;
	for (int i = 1; i <= 5; i++) 
	{
		cout << i << "��° ���� �Է�: ";
		cin >> tmp;
		result += tmp;
	}
	cout << "�հ� : " << result << "\n\n";
	
	// 2. �̸�, ��ȭ��ȣ ���ڿ�
	cout << " 2. �̸�, ��ȭ��ȣ ���ڿ�" << "\n\n";
	char name[100];
	char phoneNum[100];
	cout << "�̸� : ";
	cin >> name;
	cout << "��ȭ��ȣ : ";
	cin >> phoneNum;
	cout << "�̸� : " << name << "\n��ȭ��ȣ : " << phoneNum << "\n\n";
	
	// 3. ������
	cout << " 3. ������" << "\n\n";
	int stage = 0;
	cout << "���� �Է��ϼ���" << "\n";
	cin >> stage;
	for (int i = 1; i < 10; i++)
		cout << stage << " X " << i << " = " << stage * i << "\n";
	
	// 4. �޿� ��� ���α׷�. 50���� �⺻�޿��� �ǸŰ����� 12%�� �� ����.
	cout << "\n 4. �޿� ��� ���α׷�. 50���� �⺻�޿��� �ǸŰ����� 12%�� �� ����." << "\n\n";
	float sale_performance = 0;	

	while (true) 
	{
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> sale_performance;
		if(sale_performance == -1)
			break;
		cout << "�̹� �� �޿�: " << sale_performance * 0.12 + 50 << "����\n";
	}
	cout << "���α׷��� �����մϴ�.";
	
	return 0;
}
