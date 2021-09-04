#include <iostream>

std::string szyfratorKolumnowy(std::string napis, std::string klucz)
{
    std::string zaszyfrowanyNapis{""};
    for (auto kluczElem : klucz)
        for (int j = 0; j < napis.length(); j++)
            if (j % klucz.length() == (int)kluczElem - 49)
                zaszyfrowanyNapis += napis[j];
    return zaszyfrowanyNapis;
}

int main(void)
{
    std::cout << szyfratorKolumnowy("koza na polu", "32514");
    return 0;
}