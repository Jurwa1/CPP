#include <iostream>
#include <cmath>

int main()
{
	for (int i{ 100 }; i < 1000; ++i) {
		int a{ i / 100 };
		int b{ i % 10 };
		int c{ i / 10 % 10 };
		if (std::pow(a, 3) + std::pow(b, 3) + std::pow(c, 3) == i) {
			std::cout << "[found!] " << i << "\n";
		}
	}
}