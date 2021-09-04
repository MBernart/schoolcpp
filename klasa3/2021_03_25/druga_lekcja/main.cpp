#include <iostream>
#include <fstream>

using std::cout;


int main()
{
    cout << "Zadanie 6.1\n"
         << "============\n";
    int temp, theBrightest{0}, theDarkest{255};
    std::ifstream fin;
    fin.open("dane.txt");
    while (!fin.eof())
    {
        fin >> temp;
        if (temp > theBrightest)
            theBrightest = temp;
        if (temp < theDarkest)
            theDarkest = temp;
    }
    fin.close();
    cout << "Najjaśniejszy: " << theBrightest
         << "\nNajciemniejszy: " << theDarkest;
    return 0;
}
