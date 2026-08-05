#include <iostream>
#include <random>
#include <string>
#include <cmath>

int RandomNum(int min, int max) {														// Генератор случайных чисел, использующийся генератором случайных карт
	static std::mt19937 x(std::random_device{}());
	std::uniform_int_distribution y{ min, max };
	int result = y(x);
	return result;
}

void CardGenerat(std::string& EveryCard, int& x, int& y) {								// Генератор случайных карт
	std::string Costs{ "23456789TJQKA" };												// Все возможные 13 достоинств карт в порядке возрастания
	std::string Suits{ "SHDC" };														// Все возможные 4 масти
	std::string CheckCard;																// Промежуточная строка, куда заносится сгенерированная карта
	while (true) {
		CheckCard = "";																	// Обнуление промежуточной строки
		x = RandomNum(0, 12);															// Генерация случайно масти
		y = RandomNum(0, 3);															// Генерация случайного достоинства
		CheckCard += Costs[x];
		CheckCard += Suits[y];
		CheckCard += " ";																// Создание карты по принципу ДостоинствоМастьРазделяющийзнак
		if (EveryCard.find(CheckCard) == std::string::npos) {							// Проверка на наличие дублирования карты. если внутри массива "EveryCard" со всеми разданными картами найдется карта с повторяющимеся одновременно достоинством и мастью, произойдет повторная генерация карты
			EveryCard += CheckCard;														// Созданная карта добавляется в конец массива
			break;
		}
	}
}

std::string CalculateRepeatCost(std::string EveryCard) {							// Функция для подсчета достоинства всех разыгранных карт игрока
	std::string Costs{ "23456789TJQKA" };
	std::string RepeatCost{ "0000000000000" };											// Массив, куда передается количество карт определенной масти. [0] - 2, [12] - A

	for (int i{ 0 }; i < EveryCard.length(); i += 3) {
		char j{ EveryCard[i] };
		++RepeatCost[Costs.find(j)];													// Увеличение количества полученных достоинств карт по индексу на 1 в массиве RepeatCost
	}
	return RepeatCost;
}

std::string CalculateRepeatSuit(std::string EveryCard) {
	std::string Suits{ "SHDC" };
	std::string RepeatSuits{ "0000" };

	for (int i{ 1 }; i < EveryCard.length(); i += 3) {
		char j{ EveryCard[i] };
		++RepeatSuits[Suits.find(j)];
	}
	return RepeatSuits;
}

std::string EveryCardChange(std::string EveryCard, int x) {
	if (x == 12) {
		EveryCard.erase(12, 6);
		EveryCard.erase(0, 6);
	}
	else {
		EveryCard.erase(x, 12);
	}
	return EveryCard;
}

int CalculateStraightFlush(std::string EveryCard) {

	std::string Suits{ "SHDC" };
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
	std::string RepeatSuits{ CalculateRepeatSuit(EveryCard) };
	char Suit;
	std::string Straight{ "0000000000000" };
	std::string Costs{ "23456789TJQKA" };
	int k{ 0 };
	bool Flag{ false };
	int Max{ -1 };

	if (RepeatSuits.find('5') != RepeatSuits.npos || RepeatSuits.find('6') != RepeatSuits.npos || RepeatSuits.find('7') != RepeatSuits.npos) { // Проверка на наличие 5, 6 или 7 одинаковых разыгранных мастей
		
		for (int i{ 0 }; i < 4;++i) {
			if (RepeatSuits[i] > '4')
				Suit = Suits[i];											// Переменная Suit принимает порядковый номер нужной масти
		}

		for (int i{ 0 }, j{ 1 }; i < EveryCard.length();i += 3, j += 3) { // i - индекс для достоинства, j - иднекс для масти. после каждой итерации переменные увеличиваются на 3, чтобы перескачить на следующее достоинство и масть
			if (Suit == EveryCard[j]) {
				Straight[Costs.find(EveryCard[i])]++;
			}
		}

		for (int i{ 0 }; i < 13;++i) {
			if (Straight[i] > '0')
				k += 1;
			else if (Straight[i] == '0')
				k = 0;

			if (k >= 5) {
				Flag = true;
				Max = i;
			}
		}
		
		if (Flag == true)
			return 1000000 + Max;

		else if (Straight[12] > '0' && Straight[0] > '0' && Straight[1] > '0' && Straight[2] > '0' && Straight[3] > '0')
			return 1000000;

		else 
			return 0;
	}
	return 0;
}

int CalculateCare(std::string EveryCard) {

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('4') != std::string::npos) {
		int kick{ 0 };
		for (int i{ 12 }; i > -1; --i) {
			if (RepeatCost[i] != '0' && RepeatCost[i] != '4') {
				kick = i;
				break;
			}
		}
		return 900000 + RepeatCost.find('4') * 15 + kick;
	}
	else
		return 0;
}

int CalculateFullHouse(std::string EveryCard) {
	int pos{ 0 };
	int k{ 0 };
	int j{ 0 };

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('3') != std::string::npos && RepeatCost.rfind('2') != std::string::npos)
		return 800000 + (RepeatCost.rfind('3') + 1) * 10 + RepeatCost.rfind('2') + 1;

	else if (RepeatCost.rfind('3') != std::string::npos and RepeatCost.rfind('3') > 0) {
		k = RepeatCost.rfind('3') + 1;
		pos = RepeatCost.rfind('3');

		if (RepeatCost.rfind('3', pos - 1) != std::string::npos) {
			j = RepeatCost.rfind('3', pos - 1);
			return 800000 + k * 10 + j + 1;
		}
	}

	return 0;
}

int CalculateFlash(std::string EveryCard) {

	std::string Costs{ "23456789TJQKA" };
	std::string Suits{ "SHDC" };
	std::string RepeatSuits{ CalculateRepeatSuit(EveryCard) };
	int Num{ -1 };
	int Max{ -1 };
	int Find;

	if (RepeatSuits.find('5') != std::string::npos)
		Num = RepeatSuits.find('5');

	else if (RepeatSuits.find('6') != std::string::npos)
		Num = RepeatSuits.find('6');

	else if (RepeatSuits.find('7') != std::string::npos)
		Num = RepeatSuits.find('7');

	if (Num != -1) {
		for (int i{ 0 }, j{ 1 }; i < EveryCard.length();i += 3, j += 3) {
			if (EveryCard[j] == Suits[Num]) {
				Find = Costs.find(EveryCard[i]);
				if (Find > Max)
					Max = Find;
			}
		}
	}

	if (Max > -1)
		return 700000 + Max;
	else
		return 0;
}

int CalculateStraight(std::string EveryCard) {
	int Ret{ 0 };
	bool Flag;
	int Max{ -1 };

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	for (int i{ 0 }; i != 13; ++i) {
		if (RepeatCost[i] != '0') {
			++Ret;
			if (Ret > 4 && i > Max)
				Max = i;
		}
		else if (RepeatCost[i] == '0') {
			Ret = 0;
		}
	}

	if (Max != -1)
		return 600000 + Max;

	else if (RepeatCost[12] != '0' && RepeatCost[0] != '0' && RepeatCost[1] != '0' && RepeatCost[2] != '0' && RepeatCost[3] != '0')
		return 600000;
	else
		return 0;
}

int CalculateSet(std::string EveryCard) {
	
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };


	if (RepeatCost.rfind('3') != std::string::npos) {
		int kick1{ -1 };
		int kick2{ -1 };

		for (int i{ 12 }; i > -1; --i) {
			if (RepeatCost[i] != '0' && RepeatCost.rfind('3') != i) {
				if (kick1 == -1)
					kick1 = i;
				else {
					kick2 = i;
						break;
				}
			}
		}
		return 500000 + RepeatCost.rfind('3') * 250 + kick1 * 15 + kick2;
	}
	return 0;
}

int CalculateTwoPair(std::string EveryCard) {
	int pos{ 0 };
	int pos1{ 0 };

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.rfind('2') != std::string::npos && RepeatCost.rfind('2') > 0) {
		int kick;
		pos = RepeatCost.rfind('2');

		if (RepeatCost.rfind('2', pos - 1) != std::string::npos) {

			pos1 = RepeatCost.rfind('2', pos - 1);

			for (int i{ 12 }; i > -1; --i) {
				kick = i;
				if (RepeatCost[i] != '0' && kick != pos && kick != pos1) {
					break;
				}
			}
			return 400000 + (pos + 1) * 250 + RepeatCost.rfind('2', pos - 1) + 1 * 15 + kick;
		}
	}

	return 0;
}

int CalculatePair(std::string EveryCard) {

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
	int pair{ 0 };
	int kick1{ 0 };
	int kick2{ 0 };
	int kick3{ 0 };


	for (int i = 12; i >= 0; --i) {
		if (RepeatCost[i] == '2') {

			pair = i + 1;
			break;
		}
	}

	for (int i = 12; i >= 0; --i) {
		if (RepeatCost[i] != '0' && RepeatCost[i] != '2') {
			if (kick1 == 0)
				kick1 = i + 1;
			else if (kick2 == 0)
				kick2 = i + 1;
			else if (kick3 == 0) {
				kick3 = i + 1;
				break;
			}
		}
	}

	if (pair != 0)
		return pair * 2700 + kick1 * 200 + kick2 * 15 + kick3;
	return 0;	
}

int CalculateHighCard(std::string EveryCard) {

	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
	int kick1{ 0 };
	int kick2{ 0 };
	int kick3{ 0 };
	int kick4{ 0 };
	int kick5{ 0 };

	for (int i{ 12 };i > -1;--i) {

		if (RepeatCost[i] != '0') {
			if (kick1 == 0)
				kick1 = i + 1;
			if (kick2 == 0)
				kick2 = i + 1;
			if (kick3 == 0)
				kick3 = i + 1;
			if (kick4 == 0)
				kick4 = i + 1;
			if (kick5 == 0) {
				kick5 = i + 1;
				break;
			}
		}
	}
	return kick1 * std::pow(10, 4) + kick2 * std::pow(10, 3) + kick3 * std::pow(10, 2) + kick4 * 10 + kick5;
}