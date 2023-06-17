#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void QuickSort(vector<T> &v, int l, int r)
{
    if (r <= l) return;

    int left = l;
    int right = r;
    T pivot = v[left];
    
    while (left < right)
    {
        while (v[right] >= pivot && left < right)
        {
            right--;
        }
        v[left] = v[right];

        while (v[left] <= pivot && left < right)
        {
            left++;
        }
        v[right] = v[left];
    }

    //pivot更新,left = right
    v[left] = pivot;

    QuickSort(v, l, right);
    QuickSort(v, right + 1, r);
    return;
}

int main(int argc, const char** argv) 
{
    vector<int> v = {1,4,2,4,6,8,88};

    QuickSort(v, 0, v.size() - 1);

    for(auto i:v)
        cout << i << " ";

    return 0;
}