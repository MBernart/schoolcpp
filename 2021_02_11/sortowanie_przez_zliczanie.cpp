#include <iostream>

void sortuj(int tab[], int n, int m)
{
    int temp[m]{0};
    for (int i = 0; i < n; i++)
        temp[tab[i]]++;
    int k = 0;
    for (int i = 0; i < m; i++)
        for (int j = temp[i]; j > 0; j--)
        {
            tab[k] = i;
            k++;
        }
}

int main(void)
{
    int tab[]{5, 4, 3, 2, 0};
    sortuj(tab, 5, 6);
    for (int i = 0; i < 5; i++)
        std::cout << tab[i] << ' ';

    return 0;
}