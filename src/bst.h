#ifndef __BST_H__ 
#define __BST_H__  

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stdlib.h>
#include <math.h>
#include "type.h"

using namespace std;

//Trabajo realizado por Maizo Diego y De Lama Kevin

/*template <class TT>
struct HeapDesc
{
  typedef TT T; 
  typedef less<T> CMP1; // por que esta parametrizado template<>
};

template <class TT>
struct HeapAsc
{
  typedef TT T; 
  typedef greater<T> CMP2; // por que esta parametrizado template<>
};*/

template <typename T>
class MinHeap 
{  
  /*typedef typename HTraits::T   T;
  typedef typename HTraits::CMP1 CMP1;
  CMP1 m_cmp;*/
  private:
      vector<T> vx; 

      T parent(T dato) 
      { return (dato - 1) / 2; }

      T left(T dato) 
      { return (2 * dato + 1);}

      T right(T dato) 
      { return (2 * dato + 2); }
      
      void down(T &dato);
      void up(const T &dato);
      
  public:
      size_t size();
      bool empty();
      void push(const T &newDato);
      void print();
};

template <typename T>
void MinHeap<T>::down(T &dato)
{
    T izq = left(dato);
    T der = right(dato);

    T menor = dato;

    if (izq < size() && vx[izq] < vx[dato]) 
    { menor = izq; }
    
    if (der < size() && vx[der] < vx[menor])
    { menor = der; }
    
    if (menor != dato)
    {
        swap(vx[dato], vx[menor]);
        down(menor);
    }
}
template <typename T>
void MinHeap<T>::up(const T &dato)
{
    if (dato && vx[parent(dato)] > vx[dato])
    {
      swap(vx[dato], vx[parent(dato)]);
      up(parent(dato));
    }
}
template <typename T>
size_t MinHeap<T>::size()
{ return vx.size(); }

template <typename T>
bool MinHeap<T>::empty()
{ return size()==0; }

template <typename T>
void MinHeap<T>::push(const T &newDato)
{
    vx.push_back(newDato);
    T index = size() - 1;
    up(index);
}

template <typename T>
void MinHeap<T>::print()
{
typename vector<T>::iterator iter1 = vx.begin();
cout<<"Min Heap:"<<" ";
for(; iter1!=vx.end(); iter1++)
  cout<<*iter1<<" ";
}

template <typename T>
class MaxHeap 
{  
  /*typedef typename HTraits::T   T;
  typedef typename HTraits::CMP1 CMP1;
  CMP1 m_cmp;*/
  private:
      vector<T> mx; 

      T parent(T dato) 
      { return (dato - 1) / 2; }

      T left(T dato) 
      { return (2 * dato + 1);}

      T right(T dato) 
      { return (2 * dato + 2); }
      
      void down(T &dato);
      void up(const T &dato);
      
  public:
      size_t size();
      bool empty();
      void push(const T &newDato);
      void print();
};

template <typename T>
void MaxHeap<T>::down(T &dato)
{
    T izq = left(dato);
    T der = right(dato);
    T menor = dato;
    
    if (izq < size() && mx[izq] > mx[dato]) 
    { menor = izq; }
    
    if (der < size() && mx[der] > mx[menor])
    { menor = der; }
    
    if (menor != dato)
    {
        swap(mx[dato], mx[menor]);
        down(menor);
    }
}
template <typename T>
void MaxHeap<T>::up(const T &dato)
{
    if (dato && mx[parent(dato)] < mx[dato])
    {
        swap(mx[dato], mx[parent(dato)]);
        up(parent(dato));
    }
}
template <typename T>
size_t MaxHeap<T>::size()
{ return mx.size(); }

template <typename T>
bool MaxHeap<T>::empty()
{ return size()==0; }

template <typename T>
void MaxHeap<T>::push(const T &newDato)
{
    mx.push_back(newDato);
    T index = size() - 1;
    up(index);
}
template <typename T>
void MaxHeap<T>::print()
{
typename vector<T>::iterator iter1 = mx.begin();
cout<<"Max Heap:"<<" ";
for(; iter1!=mx.end(); iter1++)
  cout<<*iter1<<" ";
}





#endif
