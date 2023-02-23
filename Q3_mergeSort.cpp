#include <iostream> 
using namespace std; 

void merge(int arr[], int initial, int mid, int end) {
  int len1 = mid - initial + 1;
  int len2 = end - mid;
  int array1[len1];
  int array2[len2];
  // copying arrays
  for (int i = 0; i < len1; i++) {
    array1[i] = arr[i];
  }
  for (int i = 0; i < len2; i++) {
    array2[i] = arr[mid + 1 + i];
  }
  // sorting and merging
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < len1 && j < len2) {
    if (array1[i] <= array2[j]) {
      arr[k] = array1[i];
      k++;
      i++;
    } else {
      arr[k] = array2[j];
      k++;
      j++;
    }
  }
  while (i < len1) {
    arr[k] = array1[i];
    k++;
    i++;
  }
  while (j < len2) {
    arr[k] = array2[j];
    k++;
    j++;
  }
}

void mergeSort(int input[], int size) {
  int initial = 0;
  int end = size - 1;
  if (initial < end) {
    int mid = (initial + end) / 2;
    mergeSort(input, mid + 1);
    mergeSort(input + mid + 1, size - mid - 1);
    merge(input, initial, mid, end);
  }
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}