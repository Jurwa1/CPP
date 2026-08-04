#include <iostream>
#include <random>
#include <string>

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
		EveryCard.erase(x, 6);
		EveryCard.erase(0, 6);
	}
	else {
		EveryCard.erase(x, 12);
	}
	return EveryCard;
}

int CalculateStraightFlush(std::string EveryCard, int x) {

	std::string Suits{ "SHDC" };
	EveryCard = EveryCardChange(EveryCard, x);
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
			return 10000 + Max;

		else if (Straight[12] > '0' && Straight[0] > '0' && Straight[1] > '0' && Straight[2] > '0' && Straight[3] > '0')
			return 10000;

		else 
			return 0;
	}
}

int CalculateCare(std::string EveryCard, int x) {

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('4') != std::string::npos)
		return 9000 + RepeatCost.find('4');
	else
		return 0;
}

int CalculateFullHouse(std::string EveryCard, int x) {
	int pos{ 0 };
	int k{ 0 };
	int j{ 0 };

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('3') != std::string::npos && RepeatCost.rfind('2') != std::string::npos)
		return 8000 + (RepeatCost.rfind('3') + 1) * 10 + RepeatCost.rfind('2') + 1;

	else if (RepeatCost.rfind('3') != std::string::npos and RepeatCost.rfind('3') > 0) {
		k = RepeatCost.rfind('3') + 1;
		pos = RepeatCost.rfind('3');

		if (RepeatCost.rfind('3', pos - 1) != std::string::npos) {
			j = RepeatCost.rfind('3', pos - 1);
			return 8000 + k * 10 + j + 1;
		}
	}

	return 0;
}

int CalculateFlash(std::string EveryCard, int x) {

	std::string Costs{ "23456789TJQKA" };
	std::string Suits{ "SHDC" };
	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatSuits{ CalculateRepeatSuit(EveryCard) };
	int Num;
	int Max{ -1 };

	if (RepeatSuits.find('5') != std::string::npos)
		Num = RepeatSuits.find('5');

	else if (RepeatSuits.find('6') != std::string::npos)
		Num = RepeatSuits.find('6');

	else if (RepeatSuits.find('7') != std::string::npos)
		Num = RepeatSuits.find('7');

	for (int i{ 0 }, j{ 1 }; i < EveryCard.length();i += 3, j += 3) {
		if (EveryCard[j] == Suits[Num]) {
			if (Costs.find(EveryCard[i]) > Max)
				Max = Costs.find(EveryCard[i]);
		}
	}

	if (Max > -1)
		return 7000 + Max;
	else
		return 0;
}

int CalculateStraight(std::string EveryCard, int x) {
	int Ret{ 0 };
	bool Flag;
	int Max{ -1 };

	EveryCard = EveryCardChange(EveryCard, x);
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
		return 6000 + Max;

	else if (RepeatCost[12] != '0' && RepeatCost[0] != '0' && RepeatCost[1] != '0' && RepeatCost[2] != '0' && RepeatCost[3] != '0')
		return 6003;
	else
		return 0;
}

int CalculateSet(std::string EveryCard, int x) {

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('3') != std::string::npos)
		return 5000 + RepeatCost.rfind('3');
	return 0;
}

int CalculateTwoPair(std::string EveryCard, int x) {
	int pos{ 0 };

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.rfind('2') != std::string::npos && RepeatCost.rfind('2') > 0) {
		pos = RepeatCost.rfind('2');

		if (RepeatCost.rfind('2', pos - 1) != std::string::npos)
			return 4000 + (pos + 1) * 10 + RepeatCost.rfind('2', pos - 1);
	}

	return 0;
}

int CalculatePair(std::string EveryCard, int x) {

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	if (RepeatCost.find('2') != std::string::npos)
		return 2000 + RepeatCost.find('2');
	return 0;
}

int CalculateHighCard(std::string EveryCard, int x) {

	EveryCard = EveryCardChange(EveryCard, x);
	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };

	for (int i{ 12 };i > -1;--i) {
		char j;
		j = RepeatCost[i];
		if (j != '0')
			return i;
	}
	return 0;
}