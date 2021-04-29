#include <iostream>

using namespace std;

void bubbleSort(string &s1)
{
    for (int i = 0; i < s1.size() - 1; i++)
        for (int j = 0; j < s1.size() - 1; j++)
            if (s1[j] < s1[j + 1])
                swap(s1[j], s1[j + 1]);
}

bool isAnaagram(string s1, string s2)
{
    int tab[256]{};
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        tab[s1[i]]++;
        tab[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)
        if (tab[i] != 0)
            return false;
    return true;
}

bool isAnaagram2(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    bubbleSort(s1);
    bubbleSort(s2);
    return s1 == s2;
}

int main(void)
{
    cout << isAnaagram("abcde", "ebdca") << '\n'
         << isAnaagram2("abcde", "ebdca") << '\n';

    return 0;
}