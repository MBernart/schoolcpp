#include <iostream>
#include <math.h>

using namespace std;

int liczba, a;
string hexade = ""; 

int main()
{
    cout << "Podaj liczbę w systemie dziesiętnym: ";
    cin >> liczba;
    a = liczba;
    do
    {
        
        if (a % 16 < 10)
            hexade = to_string(a%16) + hexade;
        else if (a % 16 == 10)
            hexade = "A" + hexade;
        else if (a % 16 == 11)
            hexade = "B" + hexade;
        else if (a % 16 == 12)
            hexade = "C" + hexade;
        else if (a % 16 == 13)
            hexade = "D" + hexade;
        else if (a % 16 == 14)
            hexade = "E" + hexade;
        else if (a % 16 == 15)
            hexade = "F" + hexade;

        a /= 16;

    } while (a > 0);
    cout << hexade;
    
    return 0;
}