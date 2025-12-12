#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
	if (arr.size() == 0) return arr;
	
	int length = arr.size();

	for (int i = 0; i < length; i++) {
		int currentElement = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > currentElement) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = currentElement;
	}
	return arr;
}


vector<int> brutalForce(vector<int> manyA, vector<int> manyB) {

	int lengthA = manyA.size();
	int lengthB = manyB.size();

	vector<int> cross;

	for (int i = 0; i < lengthA; i++) {
		for (int j = 0; j < lengthB; j++) {
			if (manyA[i] == manyB[j]) {
				cross.push_back(manyA[i]);
			}
		}
	}

	return insertionSort(cross);

};

vector<int> findDubles(vector<int> arr) {
	int length = arr.size();

	vector<int> RESULT;

	for (int i = 0; i < length; i++) {
		if (i == length - 1 || arr[i] != arr[i + 1]) {
			RESULT.push_back(arr[i]);
		}
	}

	return RESULT;
}

int main()
{
	vector<int> manyA = { 1, 2, 3, 4, 5, 6, 7, 8, 8 };
	vector<int> manyB = { 9, 10, 11, 12, 13, 14, 15, 8 };

	vector<int> brutalForceResult = brutalForce(manyA, manyB);
	vector<int> result = findDubles(brutalForceResult);
	for (int number : result) {
		cout << number << " ";
	};

	return 0;
}