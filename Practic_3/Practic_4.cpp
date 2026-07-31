#include <iostream>

int main() {
	for (int i{ 1 }; i < 31; ++i) {
		int summ{ 0 };
		for (int j{ 2 }; j <= i; ++j) {
			if (i % j == 0)
			{
				++summ;
			}
		}
		if (summ == 1) {
			std::cout << "number " << i << " is primal number" << "\n";
		}
	}
}