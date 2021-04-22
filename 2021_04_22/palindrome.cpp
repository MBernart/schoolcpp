#include <iostream>

using namespace std;

bool isPalindrome(string w)
{
    string word{""};
    for (int i = 0; i < w.size(); i++)
        if (w[i] != ' ')
            word += w[i];
    for (int i = 0, j = word.size() - 1; i < j; i++, j--)
        if (word[i] != word[j])
            return false;
    return true;
}

bool isPalindrome2(string w)
{
    string word{""}, word1{""};
    for (int i = 0, j = w.size() - 1; i < w.size(); i++)
    {
        if (w[i] != ' ')
            word1 += w[i];
        if (w[j - i] != ' ')
            word += w[j - i];
    }
    if (word == word1)
        return true;
    return false;
}

int main(void)
{
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << '\n';
    cout << isPalindrome2(s);
    return 0;
}