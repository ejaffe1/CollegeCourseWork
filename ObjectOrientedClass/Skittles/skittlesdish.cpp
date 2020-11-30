#include "skittlesdish.h"

SkittlesDish::SkittlesDish() : count(0), color("red") { }

SkittlesDish::SkittlesDish(int initialCount, string color) :
    count(initialCount), color(color) {}

int SkittlesDish::getCount() const{
  return count;
}

string SkittlesDish::getColor() const {
  return color;
}

void SkittlesDish::addSkittles(int numToAdd) {
  count += numToAdd;
}

void SkittlesDish::eatSkittles(int numToEat) {
  if (count<numToEat) {
    cout << "You tried to eat too many :-(\n";
  } else {
    count -= numToEat;
  }
}

// == as member function
bool SkittlesDish::operator ==(const SkittlesDish& rhs) const {
  return (count==rhs.count && color==rhs.color);
}

// < as a nonmember friend function
bool operator <(const SkittlesDish& lhs, const SkittlesDish& rhs) {
  return (lhs.count < rhs.count);
}

// += as a nonmember nonfriend function
SkittlesDish operator +=(SkittlesDish& lhs, SkittlesDish& rhs) {
  if (lhs.getColor()!=rhs.getColor()) { // check for illegal combine attempt
    cout << "Error! You can't combine those dishes\n";
  } else {
    int n = rhs.getCount(); // local copy of starting value in rhs
    rhs.eatSkittles(n); // "eat" as public way of emptying rhs
    lhs.addSkittles(n); // add the same number of skittles to lhs
  }
  return lhs; // convention for +=
}
