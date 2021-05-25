#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
class minHeap{
private:
    int size;
    int capacity;
    vector<int> heap;
    int parent(int i){return (i - 1) / 2;}
    int left(int i){return 2 * i + 1;}
    int right(int i){return 2 * i + 2;}

public:
    minHeap(int capacity);
    void insert(int k);
    int extractMin();
    void heapify(int i);
    void printHeap();
};
minHeap::minHeap(int capacity){
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}
void minHeap::insert(int k){
    if(size == capacity){
        cout << "MIN HEAP FULL!" << endl;
        return;
    }
    size++;
    int i = size - 1;
    heap[i] = k;
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void minHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if((l < size) && (heap[l] < heap[smallest])){
        smallest = l;
    }if((r < size) && (heap[r] < heap[smallest])){
        smallest = r;
    }
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
int minHeap::extractMin(){
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
void minHeap::printHeap(){
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
    minHeap heap(N);
    for(int i = 0; i < N; i++){
        cout << "Inserting element " << i+1 << endl;
        heap.insert(rand() % 100);
        heap.printHeap();
        cout << endl;
    }

    return 0;
}
