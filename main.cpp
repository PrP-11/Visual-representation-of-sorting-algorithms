#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
// #include <string>
using namespace std;

class Graph{

  private:

    enum Colors {
      BLACK = 0,
      GREEN = 2,
      RED = 4,
      WHITE = 16
    };

    int top = 10;
    int left = 10;
    int right = 630;
    int bottom = 470;
    int barWidth = 2;
    int barGap = 1;

    void barColor(int index, int value, enum Colors color){
      int x = left + (index+1)*(barWidth+barGap);
      setcolor(color);
      bar(x, bottom-value, x+barWidth, bottom-1);
    }

    void addBar(int index, int value){
      barColor(index, value, WHITE);
    }

    void deleteBar(int index){
      barColor(index, bottom-top, BLACK);
    }

    void generateGraph(int arr[], int n, char s[]){
      setcolor(WHITE);
      outtextxy(0, 0, s);
      // y axis line
      line(left, top, left, bottom);

      // x axis line
      line(left, bottom, right, bottom);

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
    // Selection Sort
    void selectionSort(int arr[], int n, float time){
      generateGraph(arr, n, "Selection Sort");

      int i, j, min_in;

      // One by one move boundary of unsorted subarray
      for(i = 0; i < n-1; i++){
        // Find the minimum element
        min_in = i;
        barColor(min_in, arr[min_in], RED);
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_in]){
            barColor(min_in, arr[min_in], WHITE);
            min_in = j;
            barColor(min_in, arr[min_in], RED);
          }
        }

        // Swap minimum with first element
        barColor(i, arr[i], RED);
        delay(time*1000);
        swap(i, min_in, arr);
      }
      barColor(i, arr[i], GREEN);
    }

    // Insertion Sort
    void insertionSort(int arr[], int n, float time){
      generateGraph(arr, n, "Insertion Sort");
      int i, key, j;
      for(i=1;i<n;i++){
        barColor(i, arr[i], GREEN);
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
          barColor(j, arr[j], RED);
          delay(time*1000/2);
          deleteBar(j + 1);
          arr[j + 1] = arr[j];
          barColor(j + 1, arr[j + 1], WHITE);
          j = j - 1;
        }
        
        delay(time*1000/2);
        deleteBar(j + 1);
        arr[j + 1] = key;
        barColor(j + 1, arr[j + 1], WHITE);
      }
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
  int n=200;
  int arr[n];
  // range of numbers from 0 to n-1
  int range = 460;
  // time inverval for each operation in seconds
  float time = 0.025;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  Graph graph;

  getRandomArray(arr, n, range);
  graph.selectionSort(arr, n, time);

  cleardevice();

  getRandomArray(arr, n, range);
  graph.insertionSort(arr, n, time/10);

  // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  getchar();
  closegraph();
  return 0;
}
