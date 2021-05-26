#include <iostream>
#include <climits>
#include <bits/stdc++.h>

//Minheap
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
	int *harr; 
	int capacity; 
	int heap_size; 
public:
	MinHeap(int capacity);
  
	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	int extractMin();

	void decreaseKey(int i, int new_val);

	int getMin() { return harr[0]; }

	void deleteKey(int i);

	void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}


void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Maxheap

using namespace std;
void max_heap(int *a, int m, int n) {
   int j, z
   z = a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] > a[j])
         j = j + 1;
      if (z> a[j])
         break;
      else if (z<= a[j]) {
         a[j / 2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = z
   return;
}
void build_maxheap(int *a,int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      max_heap(a,k,n);
   }
}
int main() {
   int n, i;
   cout<<"enter no of elements of array\n";
   cin>>n;
   int a[30];
   for (i = 1; i <= n; i++) {
     cout<<"ingrese los elementos"<<" "<<(i)<<endl;
     cin>>a[i];
   }
   build_maxheap(a,n);
   cout<<"Max Heap\n";
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
}
