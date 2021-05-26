#include <iostream>
#include <bits/stdc++.h>
#includ <bst.h>
using namespace std;

//MinHeap implementacion
int main()
{
  MinHeap h(9);
  h.insertKey(1);
  h.insertKey(7);
  h.insertKey(3);
  h.insertKey(34);
  h.insertKey(74);
  h.insertKey(22);
  h.insertKey(10);
  h.insertKey(33);
  h.insertKey(15);
  h.insertKey(11);
  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
  h.decreaseKey(2, 1);
  cout << h.getMin();
  return 0;
}

//Max Heap implementacion
int main()
{
  priority_queue <int> pq;
  pq.push(10);
  pq.push(30);
  pq.push(80);
  pq.push(20);
  pq.push(40);
  
  while (pq.empty() == false)
  {
    cout << pq.top() << " ";
    pq.pop();
  }
  
  return 0;
}
