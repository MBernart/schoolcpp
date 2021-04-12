#include <iostream>

void printTab4na5(int tab[4][5])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            std::cout << tab[i][j] << '\t';
        std::cout << '\n';
    }
}


int main()
{
    int tablica[4][5]{{1, 2, 3, 4, 5},
                      {2, 3, 4, 5, 6},
                      {3, 4, 5, 6, 7},
                      {4, 5, 6, 7, 8}};
    std::cout << "TABLICA:\n";
    printTab4na5(tablica);
    std::cout << "Który wiersz usunąć? ";
    uint indexWiersza{0};
    std::cin >> indexWiersza;

    // "usuwanie" wiersza
    if (indexWiersza < 4 & indexWiersza >= 0)
    {
        for (int i = 0; i < 5; i++)
            tablica[indexWiersza][i] = 0;
        while (indexWiersza < 3)
        {
            for (int i = 0; i < 5; i++)
                tablica[indexWiersza][i] = tablica[indexWiersza + 1][i];
            indexWiersza++;
        }
        for (int i = 0; i < 5; i++)
            tablica[3][i] = 0;
    }
    else
    {
        std::cout << "Taki wiersz nie istnieje, kończę program!";
    }
    std::cout << "Teraz tablica wygląda tak:\n";
    printTab4na5(tablica);
    return 0;
}
