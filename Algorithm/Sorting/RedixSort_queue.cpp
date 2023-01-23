// Radix Sort using Queue
#include <bits/stdc++.h>
using namespace std;

const int RANGE = 10; // number of digits (0-9)

void radixSort(int arr[], int n) {
  queue<int> q[RANGE]; // queue for each digit(0-9)

  // finding the maximum value
  int maxValue = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }

  // finding the maximum number of digits in max value
  int maxDigits = 0;
  while (maxValue != 0) {
    maxValue /= 10;
    maxDigits++;
  }

  // sorting by iterating for each digit in max value
  for (int digit = 0; digit < maxDigits; digit++) {

    // running loop for every number in array
    for (int i = 0; i < n; i++) {
      int num = arr[i];
      int lastDigit = (num / (int)pow(10, digit)) % 10; // extracting the last digit from arr[i] as is starts with 10^0 = 1 and increament % 10
      q[lastDigit].push(num);                           // pushing the arrary value to the last digit location in queue
    }

    // now placing the queue data of ith iteration in the main array
    int index = 0;
    for (int i = 0; i < RANGE; i++) { // iterating for 10 digits
      while (!q[i].empty()) {         // untill all the numbers of this digit index is empty, popping out queue
        arr[index++] = q[i].front();  // placing queues ith index data sequentially to array where array will continuously take element if available
        q[i].pop();                   // removing queues data on that digits
      }
    }
  }
}

int main(void) {
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}