#include <iostream>
#include <string>
#include "Header.h"
#include <cctype>
#include <windows.h>
#include <random>
#include "Header.h"

char Question() {

	char y;
	int x = 0;

	do {
		++x;
		if (x > 1) {
			std::cout << "\033[1A" << "\r" << "\033[J";
			std::cout << "Неверный ввод. попробуйте еще раз: ";
		}

		std::cin >> y;
		std::cin.ignore(1000, '\n');

	} while (std::toupper(y) != 'Y' && std::toupper(y) != 'N');


	return std::toupper(y);
}

int Random(int min, int max) {
	static std::mt19937 x{ std::random_device{}() };
	std::uniform_int_distribution y{ min, max };
	int result = y(x);

	return result;
}

void Time(int Return) {
	std::cout << "\n";
	for (int i{ 0 }; i < Return; ++i) {
		Sleep(1000);
		std::cout << ".";
	}

	Sleep(500);
}

void ChoiceAmmo(const Weapon(&weaponArsenal)[4],
	const Armor(&armoredArsenal)[3],
	const Helmet(&helmetArsenal)[4],
	const Item(&itemArsenal)[4],
	Object& player) {
	

	char Help{ 'N'};
	do {
		std::cout << R"(Выберите снаряжение, которое хотите поменять:
1) Оружие
2) Шлем
3) Доспех
4) Вспомогательный предмет
5) Посмотреть инвентарь
6) Отправиться в подземелье
Введите 1-6: )";

		char Choiсe{ GetChoice('1', '6') };

		switch (Choiсe) {
		case '1':
			system("cls");

			std::cout << "Выберите оружие: \n\n"
				<< "1) " << weaponArsenal[0].Name << "\n"
				<< "2) " << weaponArsenal[1].Name << "\n"
				<< "3) " << weaponArsenal[2].Name << "\n"
				<< "4) " << weaponArsenal[3].Name << "\n"
				<< "5) " << "Отмена" << "\033[7A" << "\033[18G";

			Choiсe = GetChoice('1', '5');

			if (Choiсe != '5') {
				player.CurrentWeapon = weaponArsenal[Choiсe - '1'];
			}
			system("cls");
			break;

		case '2':
			system("cls");

			std::cout << "Выберите шлем: \n\n"
				<< "1) " << helmetArsenal[0].Name << "\n"
				<< "2) " << helmetArsenal[1].Name << "\n"
				<< "3) " << helmetArsenal[2].Name << "\n"
				<< "4) " << helmetArsenal[3].Name << "\n"
				<< "5) " << "Отмена" << "\033[7A" << "\033[16G";

			Choiсe = GetChoice('1', '5');

			if (Choiсe != '5') {
				player.Head = helmetArsenal[Choiсe - '1'];
			}
			system("cls");
			break;

		case '3':
			system("cls");

			std::cout << "Выберите броню\n\n"
				<< "1) " << armoredArsenal[0].Name << "\n"
				<< "2) " << armoredArsenal[1].Name << "\n"
				<< "3) " << armoredArsenal[2].Name << "\n"
				<< "4) " << "Отмена" << "\033[7A" << "\033[16G";

			Choiсe = GetChoice('1', '4');

			if (Choiсe != '4') {
				player.Body = armoredArsenal[Choiсe - '1'];
			}
			system("cls");
			break;

		case '4':
			system("cls");

			std::cout << "Выберите вспомогательный предмет: \n\n"
				<< "1) " << itemArsenal[0].Name << "\n"
				<< "2) " << itemArsenal[1].Name << "\n"
				<< "3) " << itemArsenal[2].Name << "\n"
				<< "4) " << itemArsenal[3].Name << "\n"
				<< "5) " << "Отмена" << "\033[7A" << "\033[35G";

			Choiсe = GetChoice('1', '5');

			if (Choiсe != '5') {
				system("cls");
				
				std::cout << "Вы выбрали: " << itemArsenal[Choiсe - '1'].Name << "\nВыберите ячейку: \n\n";

				if (player.Item1.Name == "Пусто") {
					std::cout << "1) Пусто\n";
				}
				else
					std::cout << "1) " << player.Item1.Name << "\n";

				if (player.Item2.Name == "Пусто") {
					std::cout << "2) Пусто\n";
				}
				else
					std::cout << "2) " << player.Item2.Name << "\n";

				if (player.Item3.Name == "Пусто") {
					std::cout << "3) Пусто\n";
				}
				else
					std::cout << "3) " << player.Item3.Name << "\n";

				std::cout << "4) Отмена" << "\033[5A" << "\033[18G";

				char Choice1{ GetChoice('1', '4')};
					
				switch (Choice1) {

				case '1':
					player.Item1 = itemArsenal[Choiсe - '1'];
					break;

				case '2':
					player.Item2 = itemArsenal[Choiсe - '1'];
					break;

				case '3':
					player.Item3 = itemArsenal[Choiсe - '1'];
					break;

				case '4':
					break;
				}
				system("cls");
			}
			break;

		case '5':
			system("cls");
			std::cout << "========================================\n"
				<< "            ИНВЕНТАРЬ ИГРОКА            \n"
				<< "========================================\n\n";

			std::cout << "            [ ЭКИПИРОВКА ]\n\n"
				<< "  Оружие:  " << player.CurrentWeapon.Name << "\n"
				<< "  Шлем:    " << player.Head.Name << "\n"
				<< "  Броня:   " << player.Body.Name << "\n\n";

			std::cout << "     [ ВСПОМОГАТЕЛЬНЫЕ ПРЕДМЕТЫ ]\n\n"
				<< "  1) " << player.Item1.Name << "\n"
				<< "  2) " << player.Item2.Name << "\n"
				<< "  3) " << player.Item3.Name << "\n\n";

			std::cout << "  Для продолжения нажмите любую кнопку\n========================================\n\n";

			system("pause > nul");
			system("cls");
			break;

		case '6':
			system("cls");

			std::cout << "Вы уверены?\nПосле начала вылазки поменять сняряжение будет нельзя\nY/N: ";

			Help = Question();

			break;
		}
	} while (Help != 'Y');
}

char GetChoice(char min, char max) {
	char Choise;

	do {

		std::cin >> Choise;
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		if (Choise < min || Choise > max) {
			std::cout << "\033[1A\033[2K\r"
				<< "Введите " << min << "-" << max << ": " << "\nОшибка ввода.Попробуйте еще раз"
				<< "\033[1A\033[14G";
		}

	} while (Choise < min || Choise > max);

	return Choise;
}