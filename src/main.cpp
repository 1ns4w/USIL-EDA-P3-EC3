#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class maxHeap{
private:
    
    int size;
    int capacity;
    vector<int> heap;
    int parent(int i){return (i - 1) / 2;}
    int left(int i){return 2 * i + 1;}
    int right(int i){return 2 * i + 2;}

public:
    
    maxHeap(int capacity);
    void insert(int k);
    int extractMax();
    void heapify(int i);
    void printHeap();
};

maxHeap::maxHeap(int capacity){
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

void maxHeap::insert(int k){
    if(size == capacity){
        cout << "MAX HEAP FULL!" << endl;
        return;
    }
    size++;

    int i = size - 1;
    heap[i] = k;
    while(i != 0 && heap[parent(i)] < heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void maxHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if((l < size) && (heap[l] > heap[largest])){
        largest = l;
    }if((r < size) && (heap[r] > heap[largest])){
        largest = r;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

int maxHeap::extractMax(){
    if(size == 0){
        cout << "EMPTY HEAP" << endl;
        return -1;
    }else if(size == 1){
        size--;
        return heap[0];
    }else{
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }
}
void maxHeap::printHeap(){
    int power = 0;
    int value = 1;
    for(int i = 0; i < size; i++){
        if(i == value){
            cout << endl;
            power += 1;
            value += (1 << power);
        }
        cout << heap[i] << "  ";
    }
    cout << endl;
}

int main(){
    int N = 15;
    maxHeap heap(N);
    for(int i = 0; i < N; i++){
        cout << "Inserting element " << i+1 << endl;
        heap.insert(rand() % 100);
        heap.printHeap();
        cout << endl;
    }

    return 0;
}
