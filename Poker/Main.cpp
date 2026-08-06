#include <iostream>
#include <random>
#include <cmath>
#include <format>
#include "Header.h"
#include <Windows.h>
#include <cstdlib>

int main() {		
	int z;
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::string Costs{ "23456789TJQKA" };
	std::string Suits{ "SHDC" };
	std::string SuitsСonsol[] = { "♠", "♥", "♦", "♣" };
	std::string YN;

	while (true) {																
		Player Player1;
		Player Bot1;
		Player Bot2;
		Card AllCard1;
		Card AllCard2;
		Card AllCard3;
		Card AllCard4;
		Card AllCard5;																
		std::string EveryCard{ "" };
		int ScorePlayer;
		int ScoreBot1;
		int ScoreBot2;
	
		std::string PlayerCards;
		std::string Bot1Cards;
		std::string Bot2Cards;

		CardGenerat(EveryCard, Player1.PlayerCard1.Cost, Player1.PlayerCard1.Suit);
		CardGenerat(EveryCard, Player1.PlayerCard2.Cost, Player1.PlayerCard2.Suit);

		CardGenerat(EveryCard, Bot1.PlayerCard1.Cost, Bot1.PlayerCard1.Suit);
		CardGenerat(EveryCard, Bot1.PlayerCard2.Cost, Bot1.PlayerCard2.Suit);

		CardGenerat(EveryCard, Bot2.PlayerCard1.Cost, Bot2.PlayerCard1.Suit);
		CardGenerat(EveryCard, Bot2.PlayerCard2.Cost, Bot2.PlayerCard2.Suit);

		system("cls");

		PrintPreFlop(Player1);
		std::cout << "Do you want to continue play? Y/N: ";
		YN = Game(Bot1, Bot2);																	
		if (YN == "N") {
			continue;
		}
		else if (YN == "Y") {														
			if (Bot1.Flag == true || Bot2.Flag == true) {
				CardGenerat(EveryCard, AllCard1.Cost, AllCard1.Suit);
				CardGenerat(EveryCard, AllCard2.Cost, AllCard2.Suit);
				CardGenerat(EveryCard, AllCard3.Cost, AllCard3.Suit);

				system("cls");
				PrintFlop(Player1, AllCard1, AllCard2, AllCard3);
			}

			else 
				std::cout << "Player 1 and Player 2";
		}

		std::cout << "Do you want to continue play? Y/N: ";
		YN = Game(Bot1, Bot2);
		if (YN == "N")
			continue;																	// Пас
		else if (YN == "Y") {															// Чек, рейс или ререйс
			
			CardGenerat(EveryCard, AllCard4.Cost, AllCard4.Suit);

			system("cls");
			PrintTurn(Player1, AllCard1, AllCard2, AllCard3, AllCard4);

		}

		std::cout << "Do you want to continue play? Y/N: ";
		YN = Game(Bot1, Bot2);
		if (YN == "N")
			continue;																	// Пас
		else if (YN == "Y") {															// Чек, рейс или ререйс

			CardGenerat(EveryCard, AllCard5.Cost, AllCard5.Suit);
			
			system("cls");
			PrintRiver(Player1, AllCard1, AllCard2, AllCard3, AllCard4, AllCard5);
		}

		for (int i{ 0 }; i < 13; i += 6) {
			if (i == 0)
			{
				Bot2Cards = EveryCardChange(EveryCard, i);
				ScoreBot2 = CalculateScore(Bot2Cards);
				std::cout << "Bot2 cards: " << Bot2Cards << "\n";
			}

			else if (i == 6) {
				PlayerCards = EveryCardChange(EveryCard, i);
				ScorePlayer = CalculateScore(PlayerCards);
				std::cout << "Player cards: " << PlayerCards << "\n";
			}

			else {
				Bot1Cards = EveryCardChange(EveryCard, i);
				ScoreBot1 = CalculateScore(Bot1Cards);
				std::cout << "Bot1 cards: " << Bot1Cards << "\n";
			}
		}

		if (ScorePlayer > ScoreBot1 && ScorePlayer > ScoreBot2)
			std::cout << "Player win!\n";
		else if (ScoreBot1 > ScorePlayer && ScoreBot1 > ScoreBot2)
			std::cout << "Bot1 win!\n";
		else if (ScoreBot2 > ScorePlayer && ScoreBot2 > ScoreBot1)
			std::cout << "Bot2 win!\n";
		else if (ScorePlayer == ScoreBot1 && ScorePlayer > ScoreBot2)
			std::cout << "Split pot between Player and Bot1!\n";
		else if (ScorePlayer == ScoreBot2 && ScorePlayer > ScoreBot1)
			std::cout << "Split pot between Player and Bot2!\n";
		else if (ScoreBot2 == ScoreBot1 && ScoreBot2 > ScorePlayer)
			std::cout << "Split pot between Bot1 and Bot2!\n";
		else if (ScorePlayer == ScoreBot2 && ScorePlayer == ScoreBot1 && ScoreBot1 == ScoreBot2)
			std::cout << "Split pot between all players!\n";

		std::cout << "Would you like to play another game ? ";
		YN = Game(Bot1, Bot2);
		if (YN == "Y")
			continue;																	// Пас
		else if (YN == "N")
			break;
	}
}

std::string Game(Player& Bot1, Player& Bot2) {																	// Функция для выбора действия игрока во время открытия и раздачи карт
	std::string q;
	BotAlgorithmPreFlop(Bot1, Bot2);
	do {
		std::cin >> q;
		if (q == "N")
			return "N";
		else if (q != "N" && q != "Y")
			std::cout << "Error: incorrect input. Try again\n";
	} while (q != "Y" && q != "N");
	return q;
}

int CalculateScore(std::string EveryCard) {
	int Score{ 0 };
	switch (1) {
	case 1:
		Score = CalculateStraightFlush(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateCare(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateFullHouse(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateFlash(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateStraight(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateSet(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateTwoPair(EveryCard);
		if (Score != 0)
			break;
		Score = CalculatePair(EveryCard);
		if (Score != 0)
			break;
		Score = CalculateHighCard(EveryCard);
		if (Score != 0)
			break;
	}

	return Score;
}