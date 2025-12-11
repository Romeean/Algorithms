#include <iostream>
#include <vector>

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


int main()
{
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
  cout << binarySearch(arr, 7);
  return 0;
}
