#pragma once

int RandomNum(int min, int max);
std::string Game();
void CardGenerat(std::string& EveryCard, int& x, int& y);

struct Card {
	int Cost;
	int Suit;
};

struct Player {
	std::string Name;
	Card PlayerCard1;
	Card PlayerCard2;
};