#include <iostream>
double calculateCashback(double amount);

int main() {
	while (true) {
		double sale;
		int summ{ 0 };
		std::cout << "Enter purchase amount: ";
		std::cin >> summ;
		if (summ == 0) {
			break;
		}
		sale = calculateCashback(summ);
		std::cout << "Your sale is " << sale << "\n";
	}
}

double calculateCashback(double amount) {
	if (amount <= 1000)
		return amount * 1 / 100;
	else if (amount > 1000 and amount <= 5000)
		return amount * 5 / 100;
	else
		return amount * 10 / 100;
}