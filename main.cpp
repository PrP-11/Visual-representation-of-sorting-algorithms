#include <graphics.h>
#include <stdlib.h>
#include <time.h>
class Graph{
  private:
    int bottom = 470;
    int left = 10;

    void addBar(int index, int value){
      int x = left + (index+1)*6;
      bar(x, bottom-value, x+4, bottom);
    }

    void deleteBar(int index){
      int x = left + (index+1)*6;
      setcolor(BLACK);
      bar(x, 0, x+4, bottom-1);
      setcolor(WHITE);
    }

    void selectBar(int index, int value){
      int x = left + (index+1)*6;
      setcolor(GREEN);
      bar(x, bottom-value, x+4, bottom-1);
      setcolor(WHITE);
    }

    void generateGraph(int arr[], int n){
      // y axis line
      line(left, 10, 10, bottom);

      // x axis line
      line(left, 470, 600, bottom);

      for(int i=0; i<n;i++){
        addBar(i, arr[i]);
      }
    }

    void Init(){
      int gd = DETECT, gm;
      initgraph(&gd, &gm, "");
    }

  public:
    void foo(int arr[], int n, float time){
      // Initialize the graphic mode
      Init();

      generateGraph(arr, n);
      delay(time*1000);
      selectBar(11, arr[11]);
      delay(time*1000);
      deleteBar(11);

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
  int n=40;
  int arr[n];
  // range of numbers from 0 to n-1
  int range = 470;
  // time inverval for each operation in seconds
  float time = 0.5;

  Graph graph;
  getRandomArray(arr, n, range);
  graph.foo(arr, n, time);

  return 0;
}
