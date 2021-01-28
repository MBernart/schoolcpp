#include <iostream>
#include <math.h>

using namespace std;

void sieve(bool *tab, uint n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (tab[i])
            for (int j = i * i; j <= n; j += i)
                tab[j] = 0;
}

int main(void)
{
    int n;
    cin >> n;
    bool *tab = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
        tab[i] = true;
    sieve(tab, n);
    for (int i = 2; i <= n; i++)
        if (tab[i])
            cout << i << " ";
    cout << '\n';
    return 0;
}
