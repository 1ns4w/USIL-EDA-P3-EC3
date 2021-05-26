#ifndef __BST_H__ 
#define __BST_H__ 
//by jose terrones
#include <iostream> 
#include <cassert> 
#include <functional>
#include <vector>
#include "type.h"
using namespace std;

template <typename T>
struct Heaps{
  private:
    vector<T> Heap;
    T vbl;   
    T PARENT( T vbl) {return (i - 1) / 2;  }
    T LEFT( T vbl) {return (2*i + 1);  }
    T RIGHT( T vbl) {return (2*i + 2); }

    void heapify_max(T vbl)
    {
      if (vbl && Heap[PARENT(vbl)] < Heap[vbl]){
        swap(Heap[vbl], Heap[PARENT(vbl)]);
        heapify_max(PARENT(vbl));
        }
    }

    void heapify_min(T i)
    {
      if (i && Heap[PARENT(vbl)] > Heap[vbl]){
        swap(Heap[vbl], Heap[PARENT(vbl)]);
        heapify_min(PARENT(vbl));
        }
    }

  public:
    unsigned T size() { return Heap.size();  }
    void push_max(const T &data);
    void push_min(const T &data);
    void print(oestream &os);
    void heapify_max(T vbl)
    void heapify_min(T vlb)
};

template <typename T>
void Heaps<T>::push_max(const T &data)
{
  Heap.push_back(data);
  T indice = size() - 1;
  heapify_max(indice);
}

template <typename T>
void Heaps<T>::push_min(const T &data)
{
  Heap.push_back(data);
  T indice = size() - 1;
  heapify_min(indice);
}

template <typename T>
void Heaps<T>::print(oestream &os)
{
  for (i = 0; i <= size() ; i++) 
    os<<Heap[i]<<endl;
}

#endif 
