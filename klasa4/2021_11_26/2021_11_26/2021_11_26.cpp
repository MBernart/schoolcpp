// 2021_11_26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>

int getNumberOfDifferentChars(const std::string word)
{
	std::map<char, int> letters;
	for (char letter : word)
	{
		letters[letter] = 1;
	}
	return letters.size();
}

bool zad3_step(std::string word)
{
	for (int i = 0; i < word.length() - 1; i++)
	{
		if (abs(word[i] - word[i + 1]) > 10)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	auto fin = std::ifstream("sygnaly.txt");
	//auto plik = std::ifstream("przyklad.txt");
	auto fout = std::ofstream("wyniki4.txt");

	std::string myBuffer{ "" };
	std::string zad1{ "" }, zad2{ "" };
	std::vector<std::string> zad3;
	int zad2_max = 0;

	zad1.resize(64);
	int counter = 1;
	while (!fin.eof())
	{
		fin >> myBuffer;
		if (counter >= 40 && counter % 40 == 0)
		{
			zad1 += myBuffer[9];
		}
		int current_number_off_letters = getNumberOfDifferentChars(myBuffer);
		if (current_number_off_letters >= zad2_max)
		{
			zad2_max = current_number_off_letters;
			zad2.clear();
			zad2.resize(myBuffer.length());
			zad2 = myBuffer;
		}
			if (zad3_step(myBuffer))
			{
				zad3.push_back(myBuffer);
			}

		counter++;
	}
	fout << "ZAD 1: " << zad1 << "\n";
	fout << "ZAD 2: " << zad2 << " o dlugosci: " << zad2_max <<"\n";
	fout << "ZAD 3:\n";
	for (int i = 0; i < zad3.size(); i++)
	{
		fout << "\t" << zad3[i] << '\n';
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
