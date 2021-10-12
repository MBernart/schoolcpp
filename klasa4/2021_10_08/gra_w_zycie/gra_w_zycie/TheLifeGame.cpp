#include <iostream>
#include <fstream>

class TheLifeGame
{
	bool** currentGeneration;
	bool** nextGeneration;
	int rows, cols;

public:
	TheLifeGame(int rows = 12, int cols = 20)
	{
		this->rows = rows;
		this->cols = cols;
		initializeGeneration(currentGeneration);
		initializeGeneration(nextGeneration);
	}

	void printCurrentGeneration()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << ((currentGeneration[i][j]) ? "X" : ".") << " ";
			}
			std::cout << std::endl;
		}
	}

	void readCurrentGenerationFromFile(std::string path)
	{
		std::ifstream ifs(path);
		int i = 0;
		std::string line;
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
		ifs.close();
	}

	void initializeGeneration(bool**& tab)
	{
		tab = new bool* [rows];
		for (int i = 0; i < rows; i++)
		{
			tab[i] = new bool[cols];
		}
	}

	void calculateNextGeneration()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int currentNumberOfNeighbours = getNumberOfAliveNeighbours(currentGeneration, i, j);
				nextGeneration[i][j] = ((currentGeneration[i][j] && (currentNumberOfNeighbours == 2 ||
					currentNumberOfNeighbours == 3)) ||
					(!currentGeneration[i][j] && currentNumberOfNeighbours == 3));
			}
		}
		copyGeneration(nextGeneration, currentGeneration);
	}

	void copyGeneration(bool** origin, bool** target)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				target[i][j] = origin[i][j];
			}
		}
	}


	int getNumberOfAliveNeighbours(bool** gen, int currentRow, int currentColumn)
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

	void calculateNthGeneration(int n)
	{
		for (int i = 0; i < n - 1; i++)
			calculateNextGeneration();
	}
};