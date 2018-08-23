// quickSort.cpp : Implementation of the quicksort algorithm
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void quickSort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

int main()
{

  int myArr[] = {6, 9, 8, 3, 7, 3, 2};

  cout << "The Unsorted Array: " << endl;

  for (int i = 0; i < 7; i++)
  {
    cout << myArr[i] << " ";
  }

  cout << endl
       << endl;

  quickSort(myArr, 0, (sizeof(myArr) / sizeof(myArr[0])) - 1);

  cout << "The Sorted Array: " << endl;

  for (int i = 0; i < 7; i++)
  {
    cout << myArr[i] << " ";
  }

  cout << endl;

  return 0;
}

void quickSort(int *arr, int start, int end)
{
  if (start < end)
  {
    int partitionIndex = partition(arr, start, end);
    quickSort(arr, start, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, end);
  }
}

int partition(int *arr, int start, int end)
{
  int pivot = arr[end];
  int partitionIndex = start;

  for (int i = start; i < end; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[i], arr[partitionIndex]);
      partitionIndex += 1;
    }
  }
  swap(arr[partitionIndex], arr[end]);
  return partitionIndex;
}