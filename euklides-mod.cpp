#include <iostream>

using namespace std;
int a, b, r = 1;
int main()
{
    cin >> a >> b;
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
    cout << max(a, b);
    return 0;
}