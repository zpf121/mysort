#include <iostream>
#include <vector>
using namespace std;
//维护大顶堆
//一定要heapsize，不能用v.size()，原因是后期排序的时候heapsize会变化，v.size()不行(除非pop())
template <typename T>
void Heapify(vector<T> &v, int heapsize, int i)
{
    //找到父节点和子节点中最大的，然后交换
    int largest = i;
    int left_pos = 2 * i + 1;
    int right_pos = 2 * i + 2;
    if (left_pos < heapsize && v[left_pos] > v[largest])
        largest = left_pos;
    if (right_pos < heapsize && v[right_pos] > v[largest])
        largest = right_pos;

    if (largest == i) return;

    std::swap(v[i], v[largest]);
    Heapify(v, heapsize, largest);
    return;
}

template <typename T>
void HeapSort(vector<T> &v)
{
    //生成大顶堆
    /*
    *下标为i节点的父节点下标为(int)(i-1)/2
    *父节点下标为i,左子节点下标为2*i+1
    *父节点下标为i,右子节点下标为2*i+2
    */
    for (int i = (v.size() - 1 - 1) /2; i >= 0; i--)
        Heapify(v, v.size(), i);

    for (int i = v.size() - 1; i > 0; i--)
    {
        std::swap(v[0], v[i]);
        Heapify(v, i, 0);
    }
    return;
}

int main(int argc, char *argv[])
{
    vector<int> v = {1,3,2,55,7,6};

    HeapSort(v);

    for(auto i:v)
        cout << i << " ";

    return 0;
}