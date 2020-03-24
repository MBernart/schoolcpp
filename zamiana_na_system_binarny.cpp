#include <iostream>

using namespace std;

int liczba, mod = 1, a, len;
string bin = "";

int main()
{
    cin >> liczba;
    a = liczba;
    cout << "Zadanie 8a" << endl;
    do
    {
        if (a % 2 == 1)
            cout << "1";
        else
            cout << "0";
        a /= 2;

    } while (a > 0);
    cout << endl;

    a = liczba;
    cout << "Zadanie 8b" << endl;
    do
    {
        if (a % 2 == 1)
            bin = "1" + bin;
        else
            bin = "0" + bin;
        a /= 2;

    } while (a > 0);
    cout << bin << endl;

    cout << "Zadanie 8c" << endl;
    len = bin.length();
    a = liczba;
    int *tab;
    tab = new int[len];
    int c = 1;
    do
    {
        if (a % 2 == 1)
            tab[len - c] = 1;
        else
            tab[len - c] = 0;
        a /= 2;
        c++;
    } while (a > 0);
    for(int i = 0; i < len; i++)
    {
        cout << tab[i];
    }
    return 0;
}