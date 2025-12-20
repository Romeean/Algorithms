#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


int binarySearch(vector<int> arr, int element) {
  if (arr.size() == 0) return -1;

  int length = arr.size();
  int left = 0;
  int right = length - 1;


  for (int i = 0; i < length; i++) {
    int middle = left + (right - left) / 2;

    if (arr[middle] == element) {
      return middle;
    }
    if (arr[middle] < element) {
      left = middle + 1;
    }
    if (arr[middle] > element) {
      right = middle - 1;
    }
  }

  return -1;
}

vector<int> createSortedVector(int size) {
  vector<int> arr(size);

  for (int i = 0; i < size; i++) {
    arr[i] = i;   
  }

  return arr;
}


int main()
{
  srand(time(nullptr));

  int choice = -1;

  while (choice != 0){
    cout << "\nMenu:\n";
    cout << "1 - Binary search (single test)\n";
    cout << "2 - Empirical analysis (binary search)\n";
    cout << "0 - Exit\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {

      vector<int> arr = { 1,2,3,4,5,6,7,8 };
      int element;

      cout << "Enter element to search: ";
      cin >> element;

      int index = binarySearch(arr, element);

      if (index != -1)
        cout << "Element found at index: " << index << endl;
      else
        cout << "Element not found\n";
    }

    if (choice == 2) {

      int tests[3] = { 100000, 1000000, 10000000 };

      cout << "\nEmpirical analysis of binary search\n";
      cout << "----------------------------------\n";

      for (int i = 0; i < 3; i++) {

        int sizeOfArray = tests[i];
        vector<int> arr = createSortedVector(sizeOfArray);

        int target = rand() % sizeOfArray;

        clock_t start = clock();
        binarySearch(arr, target);
        clock_t end = clock();

        double timeSpent = double(end - start) / CLOCKS_PER_SEC;

        cout << "n = " << sizeOfArray
          << " | time = " << timeSpent
          << " seconds" << endl;
      }
    }

  } 

  return 0;
}
