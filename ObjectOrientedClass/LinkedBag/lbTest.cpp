#include <iostream>
#include "lbag.cpp" // linked list implementation
#include "bag.cpp" // dynamic array implementation

using namespace std;

void test1();
void test2();
void test3();

int main() {
  test1();
  test2();
  test3();
  return 0;
}

void test1() {
  cout << "\ntest 1:\n";
  LBag<int> b;
  for (int i=0; i<5; i++) {
    b.insert(i);
  }
  cout << "(" << b << ") " << (b.isSorted()?"is":"is not") << " sorted\n";
  b.~LBag<int>();
  for (int i=10; i>0; i--) {
    b.insert(i);
  }
  cout << "(" << b << ") " << (b.isSorted()?"is":"is not") << " sorted\n";
}

void test2() {
  cout << "\ntest 2:\n";
  LBag<int> b;
  for (int i=0; i<1000; i++) {
    b.insert(4);
  }
  for (int i=0; i<1000; i++) {
    b.insert(2);
  }
  cout << b.count(2) << " 2's and " << b.count(4) << " 4's\n";
  cout << b.erase(4) << " 4's erased\n";
  cout << b.count(2) << " 2's and "<< b.count(4) << " 4's\n";
}


void test3() {
  cout << "\ntest 3:\n";
  Bag<int> b;
  for (int i=0; i<5; i++) {
    b.insert(i);
  }
  for (auto e : b) cout << e*e << endl;
}
