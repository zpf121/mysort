#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void Merge(vector<T> &v, int l, int mid, int r)
{
    vector<T> temp;
    // p1->左指针，p2->右指针
    int p1 = l;
    int right = r;
    int p2 = mid+1;

    while (p1 <= mid && p2 <= right)
    {
        if (v[p1] <= v[p2])
        {
            temp.push_back(v[p1]);
            p1++;
        }
        else
        {
            temp.push_back(v[p2]);
            p2++;
        }
    }

    //push完剩下的数
    while (p1 <= mid)
    {
        temp.push_back(v[p1]);
        p1++;
    }

    while (p2 <= right)
    {
        temp.push_back(v[p2]);
        p2++;
    }
    //cp回去
    for (int i = 0; i < temp.size(); i++)
    {
        v[l+i] = temp[i];
    }

}

template <typename T>
void MergeSort(vector<T> &v, int l, int r)
{
    if (l >= r) return;

    int mid = l + (r - l)/2;

    MergeSort(v, l, mid);
    MergeSort(v, mid + 1, r);
    Merge(v, l, mid, r);

    return;
}

int main(int argc, const char** argv) 
{
    vector<int> v = {1,4,2,4,6,8,88};

    MergeSort(v, 0, v.size() - 1);

    for(auto i:v)
        cout << i << " ";

    return 0;
}