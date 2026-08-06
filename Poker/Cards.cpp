#include <iostream>
#include "Header.h"

void PrintPreFlop(Player Player1)
{
	std::string Costs{ "23456789TJQKA" };
	std::string SuitsСonsol[] = { "♠", "♥", "♦", "♣" };
	std::cout << "+-------+" << "     " << "+-------+" << "     " << "+-------+" << "     " << "+-------+" << "     " << "+-------+\n";

	std::cout << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|\n";

	std::cout << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|\n";

	std::cout << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|\n";

	std::cout << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|\n";

	std::cout << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|" << "     " << "|#######|\n";

	std::cout << "+-------+" << "     " << "+-------+" << "     " << "+-------+" << "     " << "+-------+" << "     " << "+-------+\n\n\n";


	std::cout << "Your hand:" << "\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
	std::cout << "| " << Costs[Player1.PlayerCard1.Cost] << "     |" << "     " << "| " << Costs[Player1.PlayerCard2.Cost] << "     |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|   " << SuitsСonsol[Player1.PlayerCard1.Suit] << "   |" << "     " << "|   " << SuitsСonsol[Player1.PlayerCard2.Suit] << "   |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|     " << Costs[Player1.PlayerCard1.Cost] << " |" << "     " << "|     " << Costs[Player1.PlayerCard2.Cost] << " |\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
}


void PrintFlop(Player Player1, Card AllCard1, Card AllCard2, Card AllCard3)
{
	std::string Costs{ "23456789TJQKA" };
	std::string SuitsСonsol[] = { "♠", "♥", "♦", "♣" };

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n";

	std::cout << "| " << Costs[AllCard1.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard2.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard3.Cost] << "     |     ";
	std::cout << "|#######|     ";
	std::cout << "|#######|\n";

	std::cout << "|       |     |       |     |       |     |#######|     |#######|\n";

	std::cout << "|   " << SuitsСonsol[AllCard1.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard2.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard3.Suit] << "   |     ";
	std::cout << "|#######|     ";
	std::cout << "|#######|\n";

	std::cout << "|       |     |       |     |       |     |#######|     |#######|\n";

	std::cout << "|     " << Costs[AllCard1.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard2.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard3.Cost] << " |     ";
	std::cout << "|#######|     ";
	std::cout << "|#######|\n";

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n\n\n";

	std::cout << "Your hand:" << "\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
	std::cout << "| " << Costs[Player1.PlayerCard1.Cost] << "     |" << "     " << "| " << Costs[Player1.PlayerCard2.Cost] << "     |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|   " << SuitsСonsol[Player1.PlayerCard1.Suit] << "   |" << "     " << "|   " << SuitsСonsol[Player1.PlayerCard2.Suit] << "   |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|     " << Costs[Player1.PlayerCard1.Cost] << " |" << "     " << "|     " << Costs[Player1.PlayerCard2.Cost] << " |\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
}

void PrintTurn(Player Player1, Card AllCard1, Card AllCard2, Card AllCard3, Card AllCard4)
{
	std::string Costs{ "23456789TJQKA" };
	std::string SuitsСonsol[] = { "♠", "♥", "♦", "♣" };

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n";

	std::cout << "| " << Costs[AllCard1.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard2.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard3.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard4.Cost] << "     |     ";
	std::cout << "|#######|\n";

	std::cout << "|       |     |       |     |       |     |       |     |#######|\n";

	std::cout << "|   " << SuitsСonsol[AllCard1.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard2.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard3.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard4.Suit] << "   |     ";
	std::cout << "|#######|\n";

	std::cout << "|       |     |       |     |       |     |       |     |#######|\n";

	std::cout << "|     " << Costs[AllCard1.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard2.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard3.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard4.Cost] << " |     ";
	std::cout << "|#######|\n";

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n\n\n";

	std::cout << "Your hand:" << "\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
	std::cout << "| " << Costs[Player1.PlayerCard1.Cost] << "     |" << "     " << "| " << Costs[Player1.PlayerCard2.Cost] << "     |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|   " << SuitsСonsol[Player1.PlayerCard1.Suit] << "   |" << "     " << "|   " << SuitsСonsol[Player1.PlayerCard2.Suit] << "   |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|     " << Costs[Player1.PlayerCard1.Cost] << " |" << "     " << "|     " << Costs[Player1.PlayerCard2.Cost] << " |\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
}

void PrintRiver(Player Player1, Card AllCard1, Card AllCard2, Card AllCard3, Card AllCard4, Card AllCard5)
{
	std::string Costs{ "23456789TJQKA" };
	std::string SuitsСonsol[] = { "♠", "♥", "♦", "♣" };

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n";

	std::cout << "| " << Costs[AllCard1.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard2.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard3.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard4.Cost] << "     |     ";
	std::cout << "| " << Costs[AllCard5.Cost] << "     |\n";

	std::cout << "|       |     |       |     |       |     |       |     |       |\n";

	std::cout << "|   " << SuitsСonsol[AllCard1.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard2.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard3.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard4.Suit] << "   |     ";
	std::cout << "|   " << SuitsСonsol[AllCard5.Suit] << "   |\n";

	std::cout << "|       |     |       |     |       |     |       |     |       |\n";

	std::cout << "|     " << Costs[AllCard1.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard2.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard3.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard4.Cost] << " |     ";
	std::cout << "|     " << Costs[AllCard5.Cost] << " |\n";

	std::cout << "+-------+     +-------+     +-------+     +-------+     +-------+\n\n\n";

	std::cout << "Your hand:" << "\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
	std::cout << "| " << Costs[Player1.PlayerCard1.Cost] << "     |" << "     " << "| " << Costs[Player1.PlayerCard2.Cost] << "     |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|   " << SuitsСonsol[Player1.PlayerCard1.Suit] << "   |" << "     " << "|   " << SuitsСonsol[Player1.PlayerCard2.Suit] << "   |\n";
	std::cout << "|       |" << "     " << "|       |\n";
	std::cout << "|     " << Costs[Player1.PlayerCard1.Cost] << " |" << "     " << "|     " << Costs[Player1.PlayerCard2.Cost] << " |\n";
	std::cout << "+-------+" << "     " << "+-------+\n";
}