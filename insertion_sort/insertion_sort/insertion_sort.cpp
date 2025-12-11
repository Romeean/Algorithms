#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
	if (arr.size() == 0) return arr;
	
	int length = arr.size();

	for (int i = 0; i < length; i++) {
		int currentElement = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > currentElement) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = currentElement;
	}
	return arr;
}


int main()
{

	vector<int> arr = { 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> result = insertionSort(arr);
	for (int n : result) {
		cout << n << " ";
	}

	return 0;
}
