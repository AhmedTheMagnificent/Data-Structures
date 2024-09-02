#include <iostream>

using namespace std;

class MinHeap{
private:
    int capacity;
    int size;
    int *arr;
public:
    MinHeap(int cap){
        size = 0;
        capacity = cap;
        arr = new int[capacity];
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i + 1;
    }

    int right(int i){
        return 2*i + 2;
    }

    void insert(int x){
        if(size == capacity){
            cout << "Heap is full" << endl;
        }
        else{
            arr[size] = x;
            int k = size;
            size++;

            while(k > 0 && arr[parent(k)] > arr[k]){
                swap(&arr[parent(k)], &arr[k]);
                k = parent(k);
            }
        }
    }

    void heapify(int i){
        int li = left(i);
        int ri = right(i);
        int smallest = i;
        if(li < size && arr[li] < arr[smallest]){
            smallest = li;
        }
        if(ri < size && arr[ri] < arr[smallest]){
            smallest = ri;
        }
        if(i != smallest){
            swap(&arr[i], &arr[smallest]);
            heapify(smallest);
        }
    }

    int getMin(){
        return arr[0];
    }

    int extractMin(){
        if(size <= 0){
            return INT_MIN;
        }
        if(size == 1){
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void swap(int *x, int *y){
        int temp = *y;
        *y = *x;
        *x = temp;
    }

    void display(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    MinHeap h(10); // Create a min-heap with a capacity of 10
    h.insert(100);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    h.display(); // Displays the current state of the heap

    cout << "Minimum element: " << h.getMin() << endl;

    cout << "Extracting min: " << h.extractMin() << endl;
    h.display(); // Displays the heap after extraction

    return 0;
}
