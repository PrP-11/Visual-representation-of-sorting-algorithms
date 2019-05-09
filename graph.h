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
      addBar(b, arr[b]);
      arr[a] = temp;
      deleteBar(a);
      addBar(a, arr[a]);
    }

    int partition (int arr[], int low, int high, float time) {
      int pivot = arr[high];
      int i = (low - 1);

      for(int j = low; j <= high- 1; j++){
          barColor(j, arr[j], RED);
          if(arr[j] <= pivot){
            i++;
            barColor(i, arr[i], RED);
            delay(time);
            swap(i, j, arr);
          }
          barColor(j, arr[j], WHITE);
      }
      barColor(i + 1, arr[i + 1], RED);
      barColor(high, arr[high], RED);
      delay(time);
      swap(i + 1, high, arr);
      return (i + 1);
    }

    void merge(int arr[], int l, int m, int r, float time){
      int i, j, k;
      int n1 = m - l + 1;
      int n2 =  r - m;

      int L[n1], R[n2];

      for(i = 0; i < n1; i++)  L[i] = arr[l + i];
      for(j = 0; j < n2; j++)  R[j] = arr[m + 1+ j];

      //merge the partitions
      i = 0, j = 0;
      k = l;
      while(i<n1 && j<n2){
        if(L[i] <= R[j]){
          delay(time/2);
          deleteBar(k);
          addBar(k, L[i]);
          arr[k] = L[i];
          i++;
        }
        else{
          delay(time/2);
          deleteBar(k);
          addBar(k, R[j]);
          arr[k] = R[j];
          j++;
        }
        k++;
      }

      while(i < n1){
        delay(time/2);
        deleteBar(k);
        addBar(k, L[i]);
        arr[k] = L[i];
        i++;
        k++;
      }

      while(j < n2){
        delay(time/2);
        deleteBar(k);
        addBar(k, R[j]);
        arr[k] = R[j];
        j++;
        k++;
      }
    }

    void heapify(int arr[], int n, int i, float time) {
      int largest = i;
      int l = 2*i + 1;
      int r = 2*i + 2;

      if(l < n && arr[l] > arr[largest])
        largest = l;

      if(r < n && arr[r] > arr[largest])
        largest = r;

      if(largest != i){
        barColor(i, arr[i], RED);
        barColor(largest, arr[largest], RED);
        delay(time);
        swap(i, largest, arr);
        heapify(arr, n, largest, time);
      }
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
        delay(time);
        swap(i, min_in, arr);
        barColor(i, arr[i], GREEN);
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
          delay(time/2);
          deleteBar(j + 1);
          arr[j + 1] = arr[j];
          barColor(j + 1, arr[j + 1], WHITE);
          j = j - 1;
        }

        delay(time/2);
        deleteBar(j + 1);
        arr[j + 1] = key;
        barColor(j + 1, arr[j + 1], WHITE);
      }
    }

    // Quick Sort
    void quickSort(int arr[], int low, int high, float time) {
      generateGraph(arr, high+1, "Quick Sort");
      if(low < high){
        int part_indx = partition(arr, low, high, time);
        quickSort(arr, low, part_indx - 1, time);
        quickSort(arr, part_indx + 1, high, time);
      }
    }

    // Merge Sort
    void mergeSort(int arr[], int l, int r, float time){
      generateGraph(arr, r+1, "Merge Sort");
      if(l < r){
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m, time);
        mergeSort(arr, m+1, r, time);

        merge(arr, l, m, r, time);
      }
    }

    // Heap Sort
    void heapSort(int arr[], int n, float time){
      generateGraph(arr, n, "Heap Sort");

      for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, time);

      for(int i=n-1; i>=0; i--){
        barColor(0, arr[0], RED);
        barColor(i, arr[i], RED);
        delay(time);
        swap(0, i, arr);
        heapify(arr, i, 0, time);
      }
    }

};
