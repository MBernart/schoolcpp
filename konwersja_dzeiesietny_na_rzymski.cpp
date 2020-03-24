#include <iostream>

using namespace std;

int liczba;
string rzymski = "";

int main()
{

    cout << " Zadanie 2.11 " << endl;
    cout << "Podaj liczbę w systemie dziesietnym: ";
    cin >> liczba;
    while (liczba > 1000)
    {
        rzymski +="M";
        liczba -=1000;
    }
    if (liczba > 900)
    {
        rzymski += "CM";
        liczba -= 900;
    }
    if (liczba > 500)
    {
        rzymski += "D";
        liczba -= 500;
    }
    if (liczba > 400)
    {
        rzymski += "CD";
        liczba -= 400;
    }
    while (liczba > 100)
    {
        rzymski += "C";
        liczba -=100;
    }
    if (liczba > 90)
    {
        rzymski += "XC";
        liczba -= 90;
    }
    if (liczba > 50)
    {
        rzymski += "L";
        liczba -= 50;
    }
    if (liczba > 40)
    {
        rzymski += "XL";
        liczba -= 40;
    }
    while (liczba > 10)
    {
        rzymski += "X";
        liczba -= 10;
    }
    if (liczba == 9)
    {
        rzymski += "IX";
        liczba -= 9;
    }
    else while(liczba > 5)
    {
        rzymski += "I";
        liczba -= 1;
    }
    if (liczba == 5)
    {
        rzymski +=5;
        liczba -= 5;
    }
    if (liczba == 4)
    {
        rzymski += "IV";
        liczba -=4;
    }
    while (liczba > 0)
    {
        rzymski += "I";
        liczba -= 1;
    }
    
    cout << rzymski;
    return 0;
}