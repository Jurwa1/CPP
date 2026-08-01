#include <iostream>

int main()
{
	for (int i{ 1 }; i < 16; ++i)
	{
		if (i % 2 == 0)
			std::cout << "[+] " << i << "\n";
		else
			std::cout << "[-] " << i << "\n";
	}
}