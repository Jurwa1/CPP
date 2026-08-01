#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

int main() {
	std::cout << std::boolalpha;	
	std::string name{};
	int age{};
	bool x{};
	double height{};

	std::cout << "enter your full name, age and heigt" << "\n";
	std::getline(std::cin >> std::ws, name);
	std::cin >> age;
	std::cin >> height;
	x = (age > 17) ? 1 : 0;

	std::cout << "full name: " << std::string_view(name) << "\n";
	std::erase(name, ' ');
	std::cout << name.length() << " - name length" << "\n";
	std::cout << std::setprecision(3) << height << " - height" << "\n";
	std::cout << age << " - age";
	std::cout << "age of majority - " << x;
}