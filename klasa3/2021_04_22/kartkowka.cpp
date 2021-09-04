/**
 * @file kartkowka.cpp
 * @author Mateusz Bernart (mateusz.bernart@uczen.zsk.poznan.pl)
 * @brief kartkówka z zakresu tablic dwuwymiarowych i operacji na nich
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ifstream fin("dane.txt");
    ofstream fout("mateusz_bernart_wyniki.txt");
    int l_wierszy, l_kolumn, temp;
    fin >> l_wierszy;
    fin >> l_kolumn;
    int **tab = new int *[l_wierszy];
    for (int i = 0; i < l_wierszy; i++)
        tab[i] = new int[l_kolumn];
    for (int i = 0; i < l_wierszy; i++)
        for (int j = 0; j < l_kolumn; j++)
        {
            fin >> temp;
            tab[i][j] = temp;
        }
    fin.close();

    fout << "->zad 1)\n";
    int min = INT32_MAX;
    for (int i = 1; i < l_wierszy; i += 2)
        for (int j = 0; j < l_kolumn; j++)
            if (tab[i][j] < min)
                min = tab[i][j];
    fout << '\t' << min << '\n';

    fout << "->zad 2)\n";
    min = INT32_MAX;
    for (int i = 0; i < l_wierszy; i += 2)
        for (int j = 0; j < l_kolumn; j++)
            if (tab[i][j] < min)
                min = tab[i][j];
    fout << '\t' << min << '\n';

    fout << "->zad 3)\n";
    int max5 = INT32_MIN, max5_1 = INT32_MIN;
    for (int i = 0; i < l_wierszy; i++)
        for (int j = 0; j < l_kolumn; j++)
        {
            if (tab[i][j] % 5 == 0)
                if (tab[i][j] > max5)
                {
                    temp = max5;
                    max5 = tab[i][j];
                    max5_1 = temp;
                }
                else if (tab[i][j] > max5_1)
                {
                    max5_1 = tab[i][j];
                }
        }
    fout << '\t' << max5 << ", " << max5_1 << '\n';

    fout << "->zad 4)\n";

    int s = 0;
    for (int i = 0; i < l_wierszy - 1; i++)
        s += tab[i][0];
    for (int i = 0; i < l_kolumn; i++)
        s += tab[l_wierszy - 1][i];
    fout << '\t' << s << '\n';

    fout << "->zad5)\n";
    for (int i = 0; i < l_wierszy; i++)
    {
        fout << '\t';
        for (int j = l_kolumn - 1; j >= 0; j--)
            fout << tab[i][j] << '\t';
        fout << '\n';
    }
    fout.close();
    return 0;
}