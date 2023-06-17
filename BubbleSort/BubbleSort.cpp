#include <iostream>
using namespace std;

template <typename T>
void Swap(T &t1, T &t2)
{
	T tmp = t1;
	t1 = t2;
	t2 = tmp;
}


template <typename T>
void BubbleSort(T arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " \n"[i == n - 1];
	}
}

int main() {
	int arr[] = {88,66,2,5,95,4,46,27};

	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

	system("pause");
	return 0;
}
