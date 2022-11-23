#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <list>
#include <math.h>
#include <numeric>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int partition(int arr[], int start, int end) {

  int pivot = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      count++;
  }
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);
  int i = start, j = end;
  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int p = partition(arr, start, end);
  quickSort(arr, start, p - 1);
  quickSort(arr, p + 1, end);
}

int random_partition(int arr[], int start, int end) {

  int pivot = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      count++;
  }
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);
  int i = start, j = end;
  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}

int partition_r(int arr[], int low, int high) {
  int random = low + rand() % (high - low);
  swap(arr[random], arr[high]);
  return partition(arr, low, high);
}

void random_quickSort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int p = partition_r(arr, start, end);
  random_quickSort(arr, start, p - 1);
  random_quickSort(arr, p + 1, end);
}

int main(int argc, char *argv[]) {
  string file = argv[1];
  ifstream input(file);
  string line = "";
  int idxM = 0;

  vector<int> numbers;

  for (std::string line; getline(input, line);) {
    numbers.push_back(stoi(line));
  }

  int numQuick[numbers.size()];
  int ranQuick[numbers.size()];

  for (int i = 0; i < numbers.size(); i++) {
    numQuick[i] = numbers[i];
    ranQuick[i] = numbers[i];
  }
  auto startR = std::chrono::high_resolution_clock::now();
  random_quickSort(ranQuick, 0, numbers.size() - 1);
  auto stopR = std::chrono::high_resolution_clock::now();
  auto durationR = duration_cast<std::chrono::microseconds>(stopR - startR);
  cout << "RANDOM QUICK SORT :" << durationR.count() << endl;
  
  auto start = std::chrono::high_resolution_clock::now();
  quickSort(numQuick, 0, numbers.size() - 1);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);
  cout << "QUICK SORT :" << duration.count() << endl;

  // cout<<"**** RANDOM SORT ****"<<endl;
  // for(int i = 0; i<numbers.size(); i++){
  //  cout<<ranQuick[i]<<endl;
  //}
  return 0;
}