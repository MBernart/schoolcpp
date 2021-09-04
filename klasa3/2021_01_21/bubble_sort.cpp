#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp(move(a));
    a = move(b);
    b = move(temp);
}


void bubbleSort(int* tab, int len)
{
    for(int j = 0; j < len; j++) 
        for (int i = 0; i < len - 1; i++)
        {
            if (tab[i] > tab[i + 1])
                swap(tab[i], tab[i+1]);
        }
}

int main(void)
{
    int* tab = new int[10] {5, 4, 3, 1, 6, 7, 8, 7, 6, 1};
    bubbleSort(tab, 10); 
    for(int i = 0; i < 10; i++)
        cout << tab[i] << " ";
    return 0;
}
