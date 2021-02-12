#include <iostream>
#include <fstream>

using namespace std;

uint getFileLength(string path)
{
    auto size{0};
    auto file{fstream(path)};
    int i;
    while (!file.eof())
    {
        file >> i;
        size++;
    }
    file.close();
    return size;
}

int *readFromFile(string path, uint length)
{
    int *tab = new int[length];
    auto file{ifstream(path)};
    auto i{0};
    while (!file.eof())
        file >> tab[i++];
    return tab;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *tab, int len)
{
    int tempMin, tempVar, maxIndex;
    for (int i = 0; i < len; i++)
    {
        tempMin = tab[i];
        maxIndex = i;
        for (int j = i + 1; j < len; j++)
            if (tab[j] < tempMin)
            {
                tempMin = tab[j];
                maxIndex = j;
            }
        if (maxIndex != i)
            swap(tab[maxIndex], tab[i]);
    }
}

void writeToFile(string path, int *tab, uint length)
{
    auto file{ofstream(path)};
    for (int i = 0; i < length; i++)
        file << tab[i] << ((i != length - 1) ? "\n" : "");

    file.close();
}

int main(void)
{
    string filename{"pp.txt"};
    auto len = getFileLength(filename);
    auto tab = readFromFile(filename, len);
    selectionSort(tab, len);
    writeToFile("output.txt", tab, len);

    return 0;
}