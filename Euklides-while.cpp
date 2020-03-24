#include <iostream>

using namespace std;

int a, b, r;

int main()
{
    cin >> a >> b;
    while (!a == 0 && !b == 0)
    {
        r = abs(a - b);
        if (a > b) a = r;
        else b = r;
    }
    a > b ? cout<<a: cout<<b;
    return 0;
}