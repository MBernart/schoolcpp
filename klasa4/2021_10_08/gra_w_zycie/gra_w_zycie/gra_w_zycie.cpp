// gra_w_zycie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readGenerationFromFile(bool** currentGeneration, string path)
{
	ifstream ifs(path);
	int i = 0;
	string line;
	while (!ifs.eof())
	{
		int j = 0;
		ifs >> line;
		for (char c : line)
		{
			if (c == '.')
			{
				currentGeneration[i][j] = false;
			}
			else
			{
				currentGeneration[i][j] = true;
			}
			j++;
		}
		i++;
	}
}

void printGeneration(bool** gen, int rows = 12, int cols = 20)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ((gen[i][j]) ? "X" : ".") << " ";
		}
		cout << endl;
	}
}

void copyGeneration(bool** origin, bool** target, int rows = 12, int cols = 20)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			target[i][j] = origin[i][j];
		}
	}
}

void initializeGeneration(bool**& tab, int rows = 12, int cols = 20)
{
	tab = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		tab[i] = new bool[cols];
	}
}

int getNumberOfAliveNeighbours(bool** gen, int currentRow, int currentColumn, int rows = 12, int cols = 20)
{
	int numberOfNeighbours{ 0 };
	for (int i = currentRow - 1; i < currentRow + 2; i++)
	{
		for (int j = currentColumn - 1; j < currentColumn + 2; j++)
		{
			if (i < 0 || j < 0 || i >= rows || j >= cols || (i == currentRow && j == currentColumn))
				continue;
			if (gen[i][j])
			{
				numberOfNeighbours++;
			}
		}
	}
	return numberOfNeighbours;
}

void calculateNextGeneration(bool** originGeneration, bool** newGeneration, int rows = 12, int cols = 20)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int currentNumberOfNeighbours = getNumberOfAliveNeighbours(originGeneration, i, j, rows, cols);
			newGeneration[i][j] = ((originGeneration[i][j] && (currentNumberOfNeighbours == 2 || currentNumberOfNeighbours == 3)) || (!originGeneration[i][j] && currentNumberOfNeighbours == 3));
		}
	}
}

int main()
{
	bool** currentGeneration;
	bool** nextGeneration;
	initializeGeneration(currentGeneration);
	initializeGeneration(nextGeneration);
	readGenerationFromFile(currentGeneration, "Dane/gra.txt");

	for (int i = 0; i < 71 - 1; i++)
	{
		calculateNextGeneration(currentGeneration, nextGeneration);
		copyGeneration(nextGeneration, currentGeneration);
	}
	printGeneration(currentGeneration);

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
