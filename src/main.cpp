#include <iostream>

// Min Heap: https://www.cs.usfca.edu/~galles/visualization/Heap.html

int main() {
  std::cout << "Hola!" << endl;
  std::cout << "Puedes encontrar el ejemplo de heap en el siguiente enlace:\n https://www.cs.usfca.edu/~galles/visualization/Heap.html" << endl;
  std::cout << "Se sugiere aplicar una reingeniería para poder hacer el max heap.";
  return 0;#include <iostream>
#include "bst.h"
#include "type.h"


using namespace std;
int main() {
MinHeap<T1> z;
MaxHeap<T1> x;

z.push(29);
z.push(10);
z.push(3);
z.push(1);
z.push(2);
z.push(12);
z.push(67);
z.push(76);
z.print();

cout<<"\n....."<<endl;
x.push(29);
x.push(10);
x.push(3);
x.push(1);
x.push(2);
x.push(12);
x.push(67);
x.push(76);
x.print();


  return 0;
}

}
