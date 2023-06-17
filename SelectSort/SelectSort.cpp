#include <iostream>
#include <vector>
using namespace std; 

template <typename T>
void SelectSort(vector<T> &v)
{
    if (v.size() <= 1)  return;
    int littlest = 0;
    for (int i = 0; i < v.size(); i++)
    {
        littlest = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[littlest] > v[j])
            {
                littlest = j;
            }
        }
        std::swap(v[i],v[littlest]);
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i == v.size() - 1];
}

int main(int argc, char *argv[])
{
    vector<int> v = {1,4,6,2,6,8,9,4,111,26};

    SelectSort(v);

    return 0;
}