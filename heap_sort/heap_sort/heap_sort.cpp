#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


void showHeap(vector<int> arr) {
  if (arr.size() == 0) return;
  
  int length = arr.size();
  int level = 0;

  while ((1 << level) - 1 < length) {
    
    int left = (1 << level) - 1;
    int right = (1 << level + 1) - 2;


    for (int j = left; j <= right && right < length; j++) {
      cout << arr[j] << " ";
    }
    cout << endl;
    level++;
  }

 }

void heapify(vector<int> &arr, int length, int i) {
  
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if(left < length && arr[largest] < arr[left]){
    largest = left;
  }
  if (right < length && arr[largest] < arr[right]) {
    largest = right;
  }
  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, length, largest);
  }

}
vector<int> heapSort(vector<int> &arr) {
  if (arr.size() == 0) return arr;
  
  int length = arr.size();
  
  for (int i = length / 2 - 1; i >= 0; i--) {
    heapify(arr, length, i);
  };

  for (int i = length - 1; i >= 0; i--) {
    swap(arr[i], arr[0]);
    heapify(arr, i, 0);
  }
  
  return arr;
}

vector<int> createRandomVector(int size) {
  vector<int> arr(size);

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % size;
  }

  return arr;
}
int main()
{
  srand(time(nullptr));

  int tests[3] = { 100000, 1000000, 10000000 };

  for (int i = 0; i < 3; i++) {

    int sizeOfArray = tests[i];

    vector<int> arr = createRandomVector(sizeOfArray);

    clock_t start = clock();
    heapSort(arr);
    clock_t end = clock();

    double timeSpent = double(end - start) / CLOCKS_PER_SEC;

    cout << "n = " << sizeOfArray
      << " | time = " << timeSpent
      << " seconds" << endl;
  }
  

  return 0;
}
