#pragma once
#include <string>

int RandomNum(int min, int max);
std::string Game();
void CardGenerat(std::string& EveryCard, int& x, int& y);

std::string CalculateRepeatCost(std::string EveryCard);
std::string CalculateRepeatSuit(std::string EveryCard);
std::string EveryCardChange(std::string EveryCard, int x);

int CalculateStraightFlush(std::string EveryCard);
int CalculateCare(std::string EveryCard);
int CalculateFullHouse(std::string EveryCard);
int CalculateFlash(std::string EveryCard);
int CalculateStraight(std::string EveryCard);
int CalculateSet(std::string EveryCard);
int CalculateTwoPair(std::string EveryCard);
int CalculatePair(std::string EveryCard);
int CalculateHighCard(std::string EveryCard);
int CalculateScore(std::string EveryCard);


struct Card {
	int Cost;
	int Suit;
};

struct Player {
	std::string Name;
	Card PlayerCard1;
	Card PlayerCard2;
};