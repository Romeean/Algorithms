#include <iostream>
#include <vector>

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
    heapify(arr, length, 0);
  }
  
  return arr;
}

int main()
{
  vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
  vector<int> result = heapSort(arr);
  
  showHeap(result);
  

  return 0;
}
