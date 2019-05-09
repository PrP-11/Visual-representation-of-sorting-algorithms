#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
using namespace std;

// generate random array of size n
int getRandomArray(int arr[], int n, int range){
  for(int i=0;i<n;i++) arr[i] = rand() % range;
  return 0;
}

// driver code
int main(){
  srand (time(NULL));
  // size of array
  int n=200;
  int arr[n];
  // range of numbers from 0 to n-1
  int range = 460;
  // time inverval for each operation in miliseconds
  float time = 5;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  Graph graph;

  // Selection Sort
  getRandomArray(arr, n, range);
  graph.selectionSort(arr, n, time);

  cleardevice();

  // Insertion Sort
  getRandomArray(arr, n, range);
  graph.insertionSort(arr, n, time);

  cleardevice();

  // Quick Sort
  getRandomArray(arr, n, range);
  graph.quickSort(arr, 0, n-1, time);

  cleardevice();

  // Merge Sort
  getRandomArray(arr, n, range);
  graph.mergeSort(arr, 0, n-1, time);

  cleardevice();

  // Heap Sort
  getRandomArray(arr, n, range);
  graph.heapSort(arr, n, time);

  // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  getchar();
  closegraph();
  return 0;
}
