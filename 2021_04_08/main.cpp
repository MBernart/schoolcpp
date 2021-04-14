/**
 * @file main.cpp
 * @author Mateusz Bernart (mateuszbernart@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ifstream fin("../dane.txt");
    int minimum{255}, maximum{0}, temp{0};
    int tab[200][320];
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 320; j++)
        {
            fin >> temp;
            tab[i][j] = temp;
        }
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 320; j++)
        {
            temp = tab[i][j];
            if (minimum > temp)
                minimum = temp;
            if (maximum < temp)
                maximum = temp;
        }
    cout << "Najjaśniejszy ma wartość: " << maximum
         << "\nNajciemniejszy ma wartość: " << minimum << "\n\n\n";
    return 0;
}

bool isPalindrome(int *tab, int n, int m)
{
}