#include <iostream>
#include "bst.h"
#include "type.h"
using namespace std;
//by jose terrones
int main()
{
	Heaps<T1> hmax;

  
  hmax.push_max(15);
  hmax.push_max(30);
  hmax.push_max(89);
  hmax.push_max(46);
  hmax.push_max(25);
  hmax.push_max(10);
  cout <<endl<< "Max Heap..." << endl;
  hmax.print();

  Heaps<T1> hmin;

  hmin.push_min(15);
  hmin.push_min(30);
  hmin.push_min(89);
  hmin.push_min(46);
  hmin.push_min(25);
  hmin.push_min(10);
  cout <<endl<< "Min Heap..." << endl;
  hmin.print();

}

