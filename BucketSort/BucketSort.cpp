#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

template <typename T>
void BucketSort(vector<T> &v)
{
    if (v.size() <= 1) return;

    int low = *std::min_element(v.begin(), v.end());
    int high = *std::max_element(v.begin(), v.end());

     int n = high - low + 1;
    std::vector<int> buckets(n);
    std::vector<int> res;

    for (auto x : v) ++buckets[x - low];
    for (int i = 0; i < n; ++i) 
    { 
        for (int j = 0; j < buckets[i]; ++j) 
        {
            res.push_back(i + low);
        }
    }

    v = res;
    return;
}


int main()
{
    vector<int> v = {9,7,5,1,3,4,11};

    BucketSort(v);
    
    for(auto i:v)
        cout << i << " ";

    return 0;
}