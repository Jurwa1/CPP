#include <iostream>
#include <cctype>
int CalculateScore(int upper, int lower, int digit, int punct, int j, int summ, int alpha);
std::string CalculateSatus(int score);
int ChekPass(std::string& Password, char& character, int& alpha, int& upper, int& lower, int& digit, int& punct, int& summ, int& j);

int main() {
	std::string Password;
	std::cout << "Enter password. A good password should contain special characters, lowercase and uppercase letters, and be longer than 7 characters.\n";
	while (true) {

		std::string question;
		int j;
		int alpha{ 0 };
		int summ{ 0 };
		int length{ 0 };
		int upper{ 0 };
		int lower{ 0 };
		int digit{ 0 };
		int punct{ 0 };
		char character;

		int score{ 0 };
		std::cin >> Password;
		j = Password.length();

		ChekPass(Password, character, alpha, upper, lower, digit, punct, summ, j);
		score = CalculateScore(upper, lower, digit, punct, j, summ, alpha);
		Password = CalculateSatus(score);
		if (Password == "N")
			return 0;

	}
}

int ChekPass(std::string& Password, char& character, int& alpha, int& upper, int& lower, int& digit, int& punct, int& summ, int& j) {
	for (int i{ 0 }; i < j; ++i) {
		character = Password[i];
		if (std::isalpha(character))
			alpha += 1;

		if (std::isupper(character)) {
			++upper;
			if (upper == 1)
				summ += 1;
		}

		else if (std::islower(character)) {
			++lower;
			if (lower == 1)
				summ += 1;
		}

		else if (std::isdigit(character)) {
			++digit;
			if (digit == 1)
				summ += 1;
		}

		else if (std::ispunct(character)) {
			++punct;
			if (punct == 1)
				summ += 1;
		}
	}
		return 0;
}

int CalculateScore(int upper, int lower, int digit, int punct, int j, int summ, int alpha) {
	int score{ 0 };
	if (upper > 0)
		score += 10;
	else
		score -= 10;

	if (lower > 0)
		score += 10;
	else
		score -= 10;

	if (digit > 0)
		score += 10;
	else
		score -= 10;

	if (punct > 0)
		score += 10;
	else
		score -= 10;

	if (j > 5 and j <= 8)
		score += 10;

	else if (j > 8 and j <= 12)
		score += 25;

	else if (j > 12)
		score += 40;

	else if (j < 4)
		score -= 40;

	if (j > 8 and summ >= 3)
		score += 20;

	if (alpha == j or digit == j)
		score -= 25;

	return score;
}

std::string CalculateSatus(int score) {
	std::string question;
	if (score <= 10) {
		std::cout << "Password is very bad. Try again\nEnter new password\n";
		return "Y";
	}

	else if (score > 10 and score < 34)
		std::cout << "Password is bad. Do you want enter new password? Y/N\n";

	else if (score > 33 and score < 67)
		std::cout << "Password is good. Do you want enter new password? Y/N\n";

	else if (score > 66)
		std::cout << "Password is very good. Do you want enter new password? Y/N\n";

	do {
		std::cin >> question;
		if (question == "Y") {
			std::cout << "Enter new password\n";
		}

		else if (question == "N") {
			std::cout << "Password set\n";
			return "N";
		}
		else
			std::cout << "Incorrect input\n";
	} while (question != "Y" and question != "N");
	return question;
}