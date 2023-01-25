#include <iostream>
int main(void) {
	char name[100];
	char lang[100];
	std::cout << "이름은 무엇입니까? ";
	std::cin >> name;

	std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
	std::cin >> lang;

	std::cout << name << std::endl;
	std::cout << lang << std::endl;
	return 0;
}

