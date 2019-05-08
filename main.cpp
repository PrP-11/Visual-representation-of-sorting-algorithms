#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Graph{

  private:

    enum Colors {
      BLACK = 0,
      GREEN = 2,
      RED = 4,
      WHITE = 16
    };

    int bottom = 470;
    int left = 10;

    void Init(){
      int gd = DETECT, gm;
      initgraph(&gd, &gm, "");
    }

    void barColor(int index, int value, enum Colors color){
      int x = left + (index+1)*6;
      setcolor(color);
      bar(x, bottom-value, x+4, bottom-1);
    }

    void addBar(int index, int value){
      barColor(index, value, WHITE);
    }

    void deleteBar(int index){
      barColor(index, bottom, BLACK);
    }

    void generateGraph(int arr[], int n){
      // y axis line
      line(left, 10, 10, bottom);

      // x axis line
      line(left, 470, 630, bottom);

      for(int i=0; i<n;i++){
        addBar(i, arr[i]);
      }
    }

    void swap(int a, int b, int arr[]){
      int temp = arr[b];
      arr[b] = arr[a];
      deleteBar(b);
      barColor(b, arr[b], WHITE);
      arr[a] = temp;
      deleteBar(a);
      barColor(a, arr[a], GREEN);
    }

  public:

    void selectionSort(int arr[], int n, float time){
      // Initialize the graphic mode
      Init();

      generateGraph(arr, n);

      int i, j, min_idx;

      // One by one move boundary of unsorted subarray
      for(i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        barColor(min_idx, arr[min_idx], RED);
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_idx]){
            barColor(min_idx, arr[min_idx], WHITE);
            min_idx = j;
            barColor(min_idx, arr[min_idx], RED);
          }
        }

        // Swap the found minimum element with the first element
        barColor(i, arr[i], RED);
        delay(time*1000);
        swap(i, min_idx, arr);
      }
      barColor(i, arr[i], GREEN);

      // Close the graphics mode and deallocates all memory allocated by graphics system
      getchar();
      closegraph();
    }

};

// generate random array of size n
int getRandomArray(int arr[], int n, int range){
  for(int i=0;i<n;i++) arr[i] = rand() % range;
  return 0;
}

// driver code
int main(){
  srand (time(NULL));
  // size of array
  int n=100;
  int arr[n];
  // range of numbers from 0 to n-1
  int range = 470;
  // time inverval for each operation in seconds
  float time = 0.05;

  Graph graph;

  // Selection Sort
  getRandomArray(arr, n, range);
  graph.selectionSort(arr, n, time);

  // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
  return 0;
}
