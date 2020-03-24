#include <iostream>

using namespace std;
int a, b, r = 1, x, p, q;
int main()
{
    cin >> a >> b;
    p = a;
    q = b;
    while (a != 0 && b != 0)
    {
        r = max(a, b) % min(a, b);
        if (a < b)
        {
            b = a;
            a = r;
        }
        else
        {

            a = b;
            b = r;
        }
    }
    x = max(a, b);
    cout << p * q / x;
    return 0;
}