// Time Complexity O(n^2)
// Bubble Sort in ascending order(a to z)

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main(void) {
  int arr[10] = {5, 3, 8, 1, 10, 6, 4, 2, 7, 9};

  bubble_sort(arr, 10);

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}