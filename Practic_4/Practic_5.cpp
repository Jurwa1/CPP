#include <iostream>
#include <random>

int main() {
	static std::mt19937 x{ std::random_device{}() };
	std::uniform_int_distribution y{ 1, 10 };
	int number = y(x);
	int z{};

	std::cout << "Enter number\n";
	do {
		std::cin >> z;
		if (z < number) {
			std::cout << "Youre number is low. Try again\n";
		}
		else if (z > number) {
			std::cout << "Youre number is big. Try again\n";
		}
	} while (z != number);
	std::cout << "Congratulation!";
}