#include <iostream>
#include <string>
#include "Header.h"
#include <windows.h>
#include <cctype>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);


	const Weapon WeaponArsenal[]{           //NAME, DAMAGE, STAMINA, STAMINA_COST
		{"Короткий Меч", 10.0, 2.0,  2.5 },
		{"Длинный Меч", 15.0, 3.0, 4.0},
		{"Топор", 20.0, 5.0, 5.5},
		{"Двуручный Топор", 30.0, 8.0, 6.5}
	};

	const Armor ArmoredArsenal[]{          //NAME, DEFENSE, STAMINA_COST
		{"Легкая Броня", 10.0, 10.0},
		{"Средняя Броня", 15.0, 20.0},
		{"Тяжелая Броня", 25.0, 30.0}
	};

	const Helmet HelmetArsenal[]{              //NAME, DEFENSE, STAMINA_COST
		{"Кожаный Капюшон", 3.0, 2.0},
		{"Кольчужный Койф", 6.0, 5.0},
		{"Железный Шлем", 10.0, 8.0},
		{"Рыцарский Бацинет", 14.0, 12.0}
	};

	const Item ItemArsenal[]{                  //NAME, EFFECT
		{"Зелье Здоровья", 50.0},
		{"Эликсир Выносливости", 35.0},
		{"Огненная Смазка", 15.0},
		{"Кусок Титанита", 1.0}
	};

	Object Player;
	Player.CurrentWeapon.Name = "Пусто";
	Player.Body.Name = "Пусто";
	Player.Head.Name = "Пусто";
	Player.Item1.Name = "Пусто";
	Player.Item2.Name = "Пусто";
	Player.Item3.Name = "Пусто";

	ChoiceAmmo(WeaponArsenal, ArmoredArsenal, HelmetArsenal, ItemArsenal, Player);

	Prologue(Player.Name);
}