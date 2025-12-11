#include <iostream>
#include <vector>

using namespace std;



vector<int> merge(vector<int> LEFT, vector<int> RIGHT) {

  int leftIndex = 0;
  int rightIndex = 0;

  vector<int> RESULT; 

  while (leftIndex < LEFT.size() && rightIndex < RIGHT.size()) {
    if (LEFT[leftIndex] > RIGHT[rightIndex]) {
      RESULT.push_back(RIGHT[rightIndex]);
      rightIndex++;
    } else if(LEFT[leftIndex] < RIGHT[rightIndex]) {
        RESULT.push_back(LEFT[leftIndex]);
        leftIndex++;
    }
  }
  while (leftIndex < LEFT.size()) {
    RESULT.push_back(LEFT[leftIndex]);
    leftIndex++;
  }
  while (rightIndex < RIGHT.size()) {
    RESULT.push_back(RIGHT[rightIndex]);
    rightIndex++;
  }

  return RESULT;
}

vector<int> divide(vector<int> arr) {
  if (arr.size() == 1) return arr;

  int length = arr.size();

  int left = 0;
  int middle = length / 2;
  int right = length;

  vector<int> LEFT;
  vector<int> RIGHT;

  for (int i = 0; i < middle; i++) {
    LEFT.push_back(arr[i]);
  }
  for (int i = middle; i < right; i++) {
    RIGHT.push_back(arr[i]);
  }

  LEFT = divide(LEFT);
  RIGHT = divide(RIGHT);
  return merge(LEFT, RIGHT);

}

int main()
{
  vector<int> arr = { 345, 23, 76, 989, 124, 459, 95, 34, 40, 99, 700 };
  vector<int> result = divide(arr);
  for (int number : result) {
    cout << number << " ";
  }

  return 0;
}
