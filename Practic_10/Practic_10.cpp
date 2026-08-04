#include <iostream>
#include <random>
#include <windows.h>
#include <format>
#include "Header.h"

int main() {																		
	std::string Costs{ "23456789TJQKA" };
	std::string Suits{ "SHDC" };
	std::string YN;

	while (true) {																		// Зацикливание игры
		Player Player1;
		Player Bot1;
		Player Bot2;
		Card AllCard1;
		Card AllCard2;
		Card AllCard3;
		Card AllCard4;
		Card AllCard5;																	// Обнуление/создание профилей игроков и карт на столе
		std::string EveryCard{ "" };													// Строка для хранения всех сгенерированных карт по принципу ДостоинствоМастьРазделяющийзнак

		CardGenerat(EveryCard, Player1.PlayerCard1.Cost, Player1.PlayerCard1.Suit);
		CardGenerat(EveryCard, Player1.PlayerCard2.Cost, Player1.PlayerCard2.Suit);

		CardGenerat(EveryCard, Bot1.PlayerCard1.Cost, Bot1.PlayerCard1.Suit);
		CardGenerat(EveryCard, Bot1.PlayerCard2.Cost, Bot1.PlayerCard2.Suit);

		CardGenerat(EveryCard, Bot2.PlayerCard1.Cost, Bot2.PlayerCard1.Suit);
		CardGenerat(EveryCard, Bot2.PlayerCard2.Cost, Bot2.PlayerCard2.Suit);

		CardGenerat(EveryCard, AllCard1.Cost, AllCard1.Suit);
		CardGenerat(EveryCard, AllCard2.Cost, AllCard2.Suit);
		CardGenerat(EveryCard, AllCard3.Cost, AllCard3.Suit);
		CardGenerat(EveryCard, AllCard4.Cost, AllCard4.Suit);
		CardGenerat(EveryCard, AllCard5.Cost, AllCard5.Suit);							// Генерация всех 11 игровых карт: 2 для игрока, 4 для ботов, 5 общих

		
		std::cout << "Your hand\nFirst card: " << Costs[Player1.PlayerCard1.Cost] << Suits[Player1.PlayerCard1.Suit] << "\n";
		std::cout << "Second card: " << Costs[Player1.PlayerCard2.Cost] << Suits[Player1.PlayerCard2.Suit] << "\n";			   // Вывод информации о картах на руках игрока во время префлопа

		YN = Game();																	// Game - функция для выбора действий со стороны игрока
		if (YN == "N")
			continue;																	// Пас
		else if (YN== "Y")																// Чек, рейс или ререйс
			std::cout << "===============\nThree community cards: " << Costs[AllCard1.Cost] << Suits[AllCard1.Suit] << " " << Costs[AllCard2.Cost] << Suits[AllCard2.Suit] << " " << Costs[AllCard3.Cost] << Suits[AllCard3.Suit] << "\n";
																						// Вывод кард на столе
		YN = Game();
		if (YN == "N")																	
			continue;																	// Пас
		else if (YN == "Y")																// Чек, рейс или ререйс
			std::cout << "===============\nFour community card: " << Costs[AllCard4.Cost] << Suits[AllCard4.Suit] << "\n";	   // Вывод четвертой карты на столе

		YN = Game();
		if (YN == "N")
			continue;																	// Пас
		else if (YN == "Y")																// Чек, рейс или ререйс
			std::cout << "===============\nFive community card: " << Costs[AllCard5.Cost] << Suits[AllCard5.Suit] << "\n";	   // Вывод пятой карты на столе
	}
}

std::string Game() {																	// Функция для выбора действия игрока во время открытия и раздачи карт
	std::string q;
	do {
		std::cout << "Do you want to continue play? Y/N: ";
		std::cin >> q;
		if (q == "N")
			return "N";
		else if (q != "N" && q != "Y")
			std::cout << "Error: incorrect input. Try again\n";
	} while (q != "Y" && q != "N");
	return q;
}

//int RandomNum(int min, int max) {														// Генератор случайных чисел, использующийся генератором случайных карт
//		static std::mt19937 x(std::random_device{}());
//		std::uniform_int_distribution y{ min, max };
//		int result = y(x);
//		return result;
//}
//
//void CardGenerat(std::string& EveryCard, int& x, int& y) {								// Генератор случайных карт
//	std::string Costs{ "23456789TJQKA" };												// Все возможные 13 достоинств карт в порядке возрастания
//	std::string Suits{ "SHDC" };														// Все возможные 4 масти
//	std::string CheckCard;																// Промежуточная строка, куда заносится сгенерированная карта
//	while(true) {
//		CheckCard = "";																	// Обнуление промежуточной строки
//		x = RandomNum(0, 12);															// Генерация случайно масти
//		y = RandomNum(0, 3);															// Генерация случайного достоинства
//		CheckCard += Costs[x];
//		CheckCard += Suits[y];
//		CheckCard += " ";																// Создание карты по принципу ДостоинствоМастьРазделяющийзнак
//		if (EveryCard.find(CheckCard) == std::string::npos) {							// Проверка на наличие дублирования карты. если внутри массива "EveryCard" со всеми разданными картами найдется карта с повторяющимеся одновременно достоинством и мастью, произойдет повторная генерация карты
//			EveryCard += CheckCard;														// Созданная карта добавляется в конец массива
//			break;
//		}
//	}
//}
//
//std::string Game() {																	// Функция для выбора действия игрока во время открытия и раздачи карт
//	std::string q;
//	do {
//		std::cout << "Do you want to continue play? Y/N: ";
//		std::cin >> q;
//		if (q == "N")
//			return "N";
//		else if (q != "N" && q != "Y")
//			std::cout << "Error: incorrect input. Try again\n";
//	} while (q != "Y" && q != "N");
//	return q;
//} 
//
//std::string CalculateRepeatCost(std::string EveryCard) {							// Функция для подсчета достоинства всех разыгранных карт игрока
//	std::string Costs{ "23456789TJQKA" };
//	std::string RepeatCost{ "0000000000000" };											// Массив, куда передается количество карт определенной масти. [0] - 2, [12] - A
//
//	for (int i{ 0 }; i < EveryCard.length(); i+=3) {									
//		char j{ EveryCard[i] };
//		++RepeatCost[Costs.find(j)];													// Увеличение количества полученных достоинств карт по индексу на 1 в массиве RepeatCost
//	}
//	return RepeatCost;
//}
//
//std::string CalculateRepeatSuit(std::string EveryCard) {							
//	std::string Suits{ "SHDC" };
//	std::string RepeatSuits{ "0000" };
//
//	for (int i{ 1 }; i < EveryCard.length(); i += 3) {
//		char j{ EveryCard[i] };
//		++RepeatSuits[Suits.find(j)];
//	}
//	return RepeatSuits;
//}
//
//std::string EveryCardChange(std::string EveryCard, int x) {
//	if (x == 12) {
//		EveryCard.erase(x, 6);
//		EveryCard.erase(0, 6);
//	}
//	else {
//		EveryCard.erase(x, 12);
//	}
//	return EveryCard;
//}
//
//int CalculateRoyalFlash(std::string EveryCard, int x) {
//	std::string StreatFlash{ "0000000000000" };
//	std::string Suits{ "SHDC" };
//	std::string Costs{ "23456789TJQKA" };
//	int ind{ 0 };
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//	std::string RepeatSuit{ CalculateRepeatSuit(EveryCard) };
//
//	for (int i{ 0 }; i != 4; ++i) {
//		char j{ RepeatSuit[i] };
//		if (j > '4') {
//			ind = i;
//			break;
//		}
//	}
//
//	for (int i{ 1 }, j{ 0 }; i < EveryCard.length(); i += 3, j += 3) {
//		if (EveryCard[i] == Suits[ind]) {
//			int costIndex = Costs.find(EveryCard[j]);
//			++StreatFlash[costIndex];
//		}
//		for (int i{ 0 }, ii{ 0 }; i < 13; ++i) {
//			char p{ StreatFlash[i] };
//			if (p != '0')
//				++ii;
//			else if (p == '0')
//				ii = 0;
//			if (ii > 4)
//				return 10;
//
//			if (i == 12 && ii == 1) {
//				for (int j{ 0 }; j != 4;++j) {
//					p = StreatFlash[j];
//					if (p != '0')
//						++ii;
//					else if (p == '0') {
//						ii = 0;
//						break;
//					}
//					if (ii > 4)
//						return 10;
//				}
//			}
//		}
//	}
//}
//
//int CalculateCare(std::string EveryCard, int x) {
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	if (RepeatCost.find('4') != std::string::npos)
//		return 9000 + RepeatCost.find('4');
//	else
//		return 0;
//}
//
//int CalculateFullHouse(std::string EveryCard, int x) {
//	int pos{ 0 };
//	int k{ 0 };
//	int j{ 0 };
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	if (RepeatCost.find('3') != std::string::npos && RepeatCost.rfind('2') != std::string::npos)
//		return 8000 + (RepeatCost.rfind('3') + 1) * 10 + RepeatCost.rfind('2') + 1;
//
//	else if (RepeatCost.rfind('3') != std::string::npos and RepeatCost.rfind('3') > 0) {
//		k = RepeatCost.rfind('3') + 1;
//		pos = RepeatCost.rfind('3');
//
//		if (RepeatCost.rfind('3', pos - 1) != std::string::npos) {
//			j = RepeatCost.rfind('3', pos - 1);
//			return 8000 + k * 10 + j + 1;
//		}
//	}
//
//	return 0;
//}
//
//int CalculateFlash(std::string EveryCard, int x) {
//
//	std::string Costs{ "23456789TJQKA" };
//	std::string Suits{ "SHDC" };
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatSuits{ CalculateRepeatSuit(EveryCard) };
//	int Num;
//	int Max{ -1 };
//
//	if (RepeatSuits.find('5') != std::string::npos)
//		Num = RepeatSuits.find('5');
//
//	else if (RepeatSuits.find('6') != std::string::npos)
//		Num = RepeatSuits.find('6');
//
//	else if (RepeatSuits.find('7') != std::string::npos)
//		Num = RepeatSuits.find('7');
//
//	for (int i{ 0 }, j{ 1 }; i < EveryCard.length();i += 3, j += 3) {
//		if (EveryCard[j] == Suits[Num]) {
//			if (Costs.find(EveryCard[i]) > Max)
//				Max = Costs.find(EveryCard[i]);
//		}
//	}
//
//	if (Max > -1)
//		return 7000 + Max;
//	else
//		return 0;
//}
//
//int CalculateStraight(std::string EveryCard, int x) {
//	int Ret{ 0 };
//	bool Flag;
//	int Max{ -1 };
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	for (int i{ 0 }; i != 13; ++i) {
//		if (RepeatCost[i] != '0') {
//			++Ret;
//			if (Ret >4 && i > Max)
//				Max = i;
//		}
//		else if (RepeatCost[i] == '0') {
//			Ret = 0;
//		}
//	}
//
//	if (Max != -1)
//		return 6000 + Max;
//
//	else if (RepeatCost[12] != '0' && RepeatCost[0] != '0' && RepeatCost[1] != '0' && RepeatCost[2] != '0' && RepeatCost[3] != '0')
//		return 6003;
//	else
//		return 0;
//}
//
//int CalculateSet(std::string EveryCard, int x) {
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	if (RepeatCost.find('3') != std::string::npos)
//		return 5000 + RepeatCost.rfind('3');
//	return 0;
//}
//
//int CalculateTwoPair(std::string EveryCard, int x) {
//	int pos{ 0 };
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	if (RepeatCost.rfind('2') != std::string::npos && RepeatCost.rfind('2') > 0) {
//		pos = RepeatCost.rfind('2');
//
//		if (RepeatCost.rfind('2', pos - 1) != std::string::npos)
//			return 4000 + (pos + 1) * 10 + RepeatCost.rfind('2', pos - 1);
//	}
//
//	return 0;
//}
//
//int CalculatePair(std::string EveryCard, int x) {
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	if (RepeatCost.find('2') != std::string::npos)
//		return 2000 + RepeatCost.find('2');
//	return 0;
//}
//
//int CalculateHighCard(std::string EveryCard, int x) {
//
//	EveryCard = EveryCardChange(EveryCard, x);
//	std::string RepeatCost{ CalculateRepeatCost(EveryCard) };
//
//	for (int i{ 12 };i > -1;--i) {
//		char j;
//		j = RepeatCost[i];
//		if (j != '0')
//			return i;
//	}
//	return 0;
//}