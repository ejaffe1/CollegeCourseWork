#include "dynamicset.h"
#include <iostream>
using namespace std;

void testInsert(DynamicSet& b); //tests the insert member function
void testContains(DynamicSet& b); //tests the contain member function
void testRemove(DynamicSet& b); //tests the remove member function
void testEquals(DynamicSet& b); //tests the overloaded Equals operator member function
void testPlusEqu(DynamicSet& b); //tests the overloaded Plus Equals operator member function
void testMinusEqu(DynamicSet& b); //tests the overloaded Minus Equals operator member function
void testTimesEqu(DynamicSet& b); //tests the overloaded Times Equals operator member function
void testPlus(DynamicSet& b); //tests the overloaded Plus operator non-member function
void testTimes(DynamicSet& b); //tests the overloaded Times operator non-member function
void testMinus(DynamicSet& b); //tests the overloaded Minus operator non-member function

int main(){
  DynamicSet b;
  testInsert(b);
  testContains(b);
  testRemove(b);
  testEquals(b);
  testPlusEqu(b);
  testMinusEqu(b);
  testTimesEqu(b);
  testPlus(b);
  testTimes(b);
  testMinus(b);
  return 0;
}

void testInsert(DynamicSet& b){
  cout<<"testInsert called..."<<endl;
  b.insert(5);
  b.insert(6);
  b.insert(8);
  cout<<"b: "<<b<<endl;
}

void testContains(DynamicSet& b){
  cout<<"\ntestContains called..."<<endl;
  cout<<"b contains 5: ";
  if(b.contains(5)){
    cout<<"True"<<endl;
  }else{
    cout<<"False"<<endl;
  }
  cout<<"b contains 10: ";
  if(b.contains(10)){
    cout<<"True"<<endl;
  }else{
    cout<<"False"<<endl;
  }
}

void testRemove(DynamicSet& b){
  cout<<"\ntestRemove called..."<<endl;
  cout<<"Removing 8 from b"<<endl;
  b.remove(8);
  cout<<"b: "<<b<<endl;
}

void testEquals(DynamicSet& b){
  cout<<"\ntestEquals called..."<<endl;
  DynamicSet b2;
  b2.insert(4);
  b2.insert(5);
  b2.insert(6);
  b2.insert(7);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  b=b2;
  cout<<"b=b2: "<<b<<endl;
}

void testPlusEqu(DynamicSet& b){
  cout<<"\ntestPlusEqu called..."<<endl;
  DynamicSet b2;
  b2.insert(2);
  b2.insert(5);
  b2.insert(3);
  b2.insert(7);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  b+=b2;
  cout<<"b+=b2: "<<b<<endl;
}

void testMinusEqu(DynamicSet& b){
  cout<<"\ntestMinusEqu called..."<<endl;
  DynamicSet b2;
  b2.insert(4);
  b2.insert(5);
  b2.insert(7);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  b-=b2;
  cout<<"b-=b2: "<<b<<endl;
}

void testTimesEqu(DynamicSet& b){
  cout<<"\ntestTimesEqu called..."<<endl;
  DynamicSet b2;
  b2.insert(6);
  b2.insert(5);
  b2.insert(3);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  b*=b2;
  cout<<"b*=b2: "<<b<<endl;
}

void testPlus(DynamicSet& b){
  cout<<"\ntestPlus called..."<<endl;
  DynamicSet b2;
  b2.insert(5);
  b2.insert(6);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  cout<<"b+b2: "<<b+b2<<endl;
}

void testTimes(DynamicSet& b){
  cout<<"\ntestTimes called..."<<endl;
  DynamicSet b2;
  b2.insert(5);
  b2.insert(6);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  cout<<"b*b2: "<<b*b2<<endl;
}

void testMinus(DynamicSet& b){
  cout<<"\ntestMinus called..."<<endl;
  DynamicSet b2;
  b2.insert(3);
  b2.insert(5);
  cout<<"b: "<<b<<endl;
  cout<<"b2: "<<b2<<endl;
  cout<<"b-b2: "<<b-b2<<endl;
}
