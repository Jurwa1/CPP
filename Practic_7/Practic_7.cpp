#include <iostream>
#include <iomanip>
#include "Header.h"

int main() {
	std::cout << std::fixed << std::setprecision(2);
	double Summ1{ 0 };
	double summ{ 0 };
	double CostWithSale{ 0 };
	double CostWithTax{ 0 };
	while (true) {
		std::cout << "Enter the price of the item or enter 0 if you want exit with out programm\n";
		std::cin >> summ;
		if (summ == 0)
			break;
		Summ1 += summ;
		CostWithSale += calculateDiscount(summ);
		CostWithTax = calculateTax(CostWithSale);
	}
	CheckScreen(Summ1, CostWithSale, CostWithTax);
}

double calculateDiscount(double x) {
	double sale;
	if (x < 1000)
		sale = 0.99;
	else if (x >= 1000 and x < 5000)
		sale = 0.95;
	else
		sale = 0.9;
	return x * sale;
}

double calculateTax(double SaleSumm) {
	return (SaleSumm * 1.13);
}

void CheckScreen(double SummOfItemPrice, double ItemPriceWithSale, double SummPriceWithTax) {
	std::cout << R"(	-- - New Order-- -
	Total summ of item price : )" << SummOfItemPrice
	<< "\n	Summ price with sale : " << ItemPriceWithSale
	<< "\n	Summ price with 13% tax : " << SummPriceWithTax

	<< "\n" << R"(	====================================
	RECEIPT
	====================================
	Subtotal : )" << SummOfItemPrice
	<< "\n	Discount : -" << SummOfItemPrice - ItemPriceWithSale
	<< "\n	Tax(13 %) : +" << SummPriceWithTax - ItemPriceWithSale
	<< "\n" << R"(	------------------------------------
	TOTAL TO PAY : )" << SummPriceWithTax
	<<"\n	====================================";
}