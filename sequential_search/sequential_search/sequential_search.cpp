#include <iostream>
#include <vector>

using namespace std;


int sequentialSearch(vector<int> arr, int element) {
  if (arr.size() == 0) return -1;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == element) return i;
  }
  
  return -1;
}

int quickSequentialSearch(vector<int> arr, int element) {
  if (arr.size() == 0) return -1;

  int lenght = arr.size();

  int i = 0;
  
  while (arr[i] != element) {
    i++;
  }
  if (i < lenght) {
    return i;
  }

  return -1;
}

int main()
{
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, };
  cout << quickSequentialSearch(arr, 8) << endl;
  cout << sequentialSearch(arr, 8) << endl;

  return 0;
}
