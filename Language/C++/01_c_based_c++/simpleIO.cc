#include <iostream>
int main(void) {
	char name[100];
	char lang[100];
	std::cout << "�̸��� �����Դϱ�? ";
	std::cin >> name;

	std::cout << "�����ϴ� ���α׷��� ���� �����ΰ���? ";
	std::cin >> lang;

	std::cout << name << std::endl;
	std::cout << lang << std::endl;
	return 0;
}

