#include <iostream>
#include <cctype>
#include "Hernya.h"
#include <string>

int main() {
	while (true){
		std::string Text;
		int Mode;
		std::string x;

		std::cout << "Enter text: ";
		std::getline(std::cin >> std::ws, Text);

		std::cout << R"(Choose mode:"
	1) Leetspeak
	2) Caesar cipher
	3) Case inversion)" << "\n";
		do {
			std::cin >> Mode;
			if (Mode != 1 && Mode != 2 && Mode != 3)
				std::cout << "Error: incorrect input. Try again\n";
		} while (Mode != 1 && Mode != 2 && Mode != 3);
		Modifier(Mode, Text);
		std::cout << Text << " - encrypted text\nDo you want try again? Y/N\n";

		do {
			std::cin >> x;
			if (x == "N")
				return 0;
			else if (x != "N" && x != "Y")
				std::cout << "Error: incorrect input. Try again\n";
		} while (x != "Y" && x != "N");
	}
}

void Modifier(int Mode, std::string& Text) {

	switch (Mode) {
	case 1:
		for (int i{ 0 }; i < Text.length(); ++i) {
			char j = Text[i];
			switch (j) {
			case 'a':
			case'A':
				j = '4';
				break;

			case 'e':
			case 'E':
				j = '3';
				break;

			case 'i':
			case 'I':
				j = '1';
				break;

			case 'o':
			case 'O':
				j = '0';
				break;
			}

			Text[i] = j;
		}
		break;

	case 2:
		int shift;
		std::cout << "Enter shift: ";
		std::cin >> shift;
		for (int i{ 0 }; i < Text.length(); ++i) {
			char j = Text[i];

			if (std::islower(j)) {
				j = (j - 'a' + shift) % 26 + 'a';
			}

			else if (std::isupper(j)) {
				j = (j - 'A' + shift) % 26 + 'A';
			}

			else if (std::isdigit(j)) {
				j = (j - '0' + shift) % 10 + '0';
			}

			Text[i] = j;

		}
		break;

	case 3:
		for (int i{ 0 }; i < Text.length(); ++i) {
			char j = Text[i];

			if (std::isupper(j))
				j = std::tolower(j);

			else if (std::islower(j))
				j = std::toupper(j);

			Text[i] = j;
		}
		break;
	}
}