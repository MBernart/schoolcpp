#include <iostream>

using namespace std;

void swap (int & a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}


void selectionSort(int* tab, int len)
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

int main(void)
{
    int *tab = new int[10] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selectionSort(tab, 10);
    for (int i = 0; i < 10; i++)
        cout << tab[i] << ' ';

    return 0;
}

