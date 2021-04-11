#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> readFromFile(string path)
{
    ifstream fin;
    fin.open(path, ios::in);
    vector<int> vec;
    int liczba;
    while (!fin.eof())
    {
        fin >> liczba;
        vec.push_back(liczba);
    }
    fin.close();
    return vec;
}

int binarySearch(vector<int> vec, int toSearch)
{
    int left = 0;
    int right = int(vec.size() - 1);
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (vec[mid] < toSearch)
            left = mid + 1;
        else if (vec[mid] > toSearch)
            right = mid - 1;
        else
            return left;
    }
    return -1;
}

int main(void)
{
    auto vec = readFromFile("liczby.txt");
    cout << binarySearch(vec, 70);

    // for (auto i : vec)
    //     cout << i << '\n';
    return 0;
}