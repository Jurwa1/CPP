#pragma once
#include <iostream>

struct Weapon {
	std::string Name;
	double Damage;
	double Stamina;
	double StaminaCost;
};

struct Armor {
	std::string Name;
	double Defense;
	double StaminaCost;
};

struct Helmet {
	std::string Name;
	double Defense;
	double StaminaCost;
};

struct Item {
	std::string Name;
	double Effect;
};

struct Object {
	std::string Name;

	Helmet Head;
	Armor Body;
	Weapon CurrentWeapon;

	Item Item1;
	Item Item2;
	Item Item3;

	double Stamina;
	double Defence;
	double Damage;
};

char GetChoice(char min, char max);
char Question();
void Time(int Return);
int Random(int min, int max);

void ChoiceAmmo(const Weapon(&weaponArsenal)[4],
	const Armor(&armoredArsenal)[3],
	const Helmet(&helmetArsenal)[4],
	const Item(&itemArsenal)[4],
	Object& player);





void Prologue(std::string& name);





