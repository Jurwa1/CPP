#include <iostream>
#include <string>
#include "Header.h"

void BotAlgorithmPreFlop(Player& Bot1, Player& Bot2) {
	if (Bot1.Flag == true) {
		int RoundScore1 = 0;

		RoundScore1 += Bot1.PlayerCard1.Cost + 1;
		RoundScore1 += Bot1.PlayerCard2.Cost + 1;
		RoundScore1 *= 2;

		if (Bot1.PlayerCard1.Cost > 9 || Bot1.PlayerCard2.Cost > 9)
			RoundScore1 += 70;

		else if (Bot1.PlayerCard1.Cost > 4 || Bot1.PlayerCard2.Cost > 4)
			RoundScore1 += 45;

		else
			RoundScore1 += 20;

		if (Bot1.PlayerCard1.Cost - Bot1.PlayerCard2.Cost == 1 || Bot1.PlayerCard1.Cost - Bot1.PlayerCard2.Cost == -1)
			RoundScore1 += 30;

		if (Bot1.PlayerCard1.Cost == Bot1.PlayerCard2.Cost)
			RoundScore1 += 50;

		if (Bot1.PlayerCard1.Suit == Bot1.PlayerCard2.Suit)
			RoundScore1 += 10;

		if (RoundScore1 > 100)
			RoundScore1 = 100;

		Bot1.Score = RoundScore1;
	}

	if (Bot2.Flag == true) {
		int RoundScore2 = 0;

		RoundScore2 += Bot2.PlayerCard1.Cost + 1;
		RoundScore2 += Bot2.PlayerCard2.Cost + 1;
		RoundScore2 *= 2;

		if (Bot2.PlayerCard1.Cost > 9 || Bot2.PlayerCard2.Cost > 9)
			RoundScore2 += 70;

		else if (Bot2.PlayerCard1.Cost > 4 || Bot2.PlayerCard2.Cost > 4)
			RoundScore2 += 45;

		else
			RoundScore2 += 20;

		if (Bot2.PlayerCard1.Cost - Bot2.PlayerCard2.Cost == 1 || Bot2.PlayerCard1.Cost - Bot2.PlayerCard2.Cost == -1)
			RoundScore2 += 30;

		if (Bot2.PlayerCard1.Cost == Bot2.PlayerCard2.Cost)
			RoundScore2 += 50;

		if (Bot2.PlayerCard1.Suit == Bot2.PlayerCard2.Suit)
			RoundScore2 += 10;

		if (RoundScore2 > 100)
			RoundScore2 = 100;

		Bot2.Score = RoundScore2;
	}
}


void BotAlgorithmFlop(std::string EveryCard, Player& Bot1, Player& Bot2) {
	std::string EveryCardBot1Al;
	std::string EveryCardBot2Al;
	if (Bot1.Flag == true) {
		int RoundScore1 = 0;
		RoundScore1 = 0;

		EveryCardBot1Al = EveryCardChange(EveryCard, 12);

		RoundScore1 = CheckHandBots(EveryCardBot1Al) + StraightDro(EveryCardBot1Al);

		Bot1.Score = RoundScore1;
	}

	if (Bot2.Flag == true) {
		int RoundScore2 = 0;
		RoundScore2 = 0;

		EveryCardBot2Al = EveryCardChange(EveryCard, 0);

		RoundScore2 = CheckHandBots(EveryCardBot2Al) + StraightDro(EveryCardBot2Al);
		
		Bot2.Score = RoundScore2;
	}
}


int CheckHandBots(std::string EveryCardBot1Al) {
	std::string RepeatCost{ CalculateRepeatCost(EveryCardBot1Al) };

	int RoundScore1{ 0 };

	switch (1) {
	case 1:
		RoundScore1 = CalculateStraightFlush(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			RoundScore1 = 100;
			break;
		}
	case 2:
		RoundScore1 = CalculateCare(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			RoundScore1 = 100;
			break;
		}
	case 3:
		RoundScore1 = CalculateFullHouse(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			RoundScore1 = 100;
			break;
		}
	case 4:
		RoundScore1 = CalculateFlash(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			RoundScore1 = 100;
			break;
		}
	case 5:
		RoundScore1 = CalculateStraight(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			RoundScore1 = 100;
			break;
		}
	case 6:
		RoundScore1 = CalculateSet(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			if (RepeatCost.rfind('3') > 8) {
				int i = RepeatCost.rfind('3');
				RoundScore1 = 90 + (i - 7);
			}
			else
				RoundScore1 = 85;
			break;
		}
	case 7:
		RoundScore1 = CalculateTwoPair(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			if (RepeatCost.rfind('2') > 8) {
				int i = RepeatCost.rfind('2');
				RoundScore1 = 70 + (i - 7);
			}
			else
				RoundScore1 = 65;
			break;
		}
	case 8:
		RoundScore1 = CalculatePair(EveryCardBot1Al);
		if (RoundScore1 != 0) {
			if (RepeatCost.rfind('2') > 8) {
				int i = RepeatCost.rfind('2');
				RoundScore1 = 55 + (i - 7);
			}
			else
				RoundScore1 = 50;
			break;
		}
	case 9:
		int q = RepeatCost.rfind('1');
		if (q > 8)
			RoundScore1 = 34 + (q - 7) * 3;
		else
			RoundScore1 = 34;
	}

	return RoundScore1;
}

int StraightDro(std::string EveryCardBot1Al) {
	int RepeatOne{ 0 };
	int RoundScore1{ 0 };
	std::string Will{ "" };
	std::string FifeCost;
	std::string RepeatCost{ CalculateRepeatCost(EveryCardBot1Al) };
	std::string RepeatSuits{ CalculateRepeatSuit(EveryCardBot1Al) };
	
	for (int i{ 0 }; i < 9;++i) {
		RepeatOne = 0;
		FifeCost = RepeatCost.substr(i, 5);
		for (int j{ 0 }; j < 5;++j) {
			if (FifeCost[j] >= '1') {
				++RepeatOne;
				if (RepeatOne == 4)
					RoundScore1 += 15;
			}
		}
	}

	if (RoundScore1 == 0) {
		Will += RepeatCost[12];
		Will += RepeatCost[0];
		Will += RepeatCost[1];
		Will += RepeatCost[2];
		Will += RepeatCost[3];

		RepeatOne = 0;

		for (int j{ 0 }; j < 5;++j) {
			if (Will[j] >= '1') {
				++RepeatOne;
			}
		}

		if (RepeatOne == 4)
			RoundScore1 += 15;
	}

	if (RepeatSuits.find('4') != std::string::npos)
		RoundScore1 += 20;

	return RoundScore1;
}