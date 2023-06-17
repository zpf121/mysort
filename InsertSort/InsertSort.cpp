#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void InsertSort(vector<T> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (v[j] < v[j - 1])
                std::swap(v[j], v[j - 1]);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " \n"[i == v.size() - 1];
    }
}

int main()
{
    vector<int> v = {1,4,5,3,1,7,9,1};

    InsertSort(v);

    return 0;
}