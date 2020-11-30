
#ifndef SKITTLESBAG_H
#define SKITTLESBAG_H

#include "skittlesdish.h"
#include <iostream>

using std::cout;

//keeps track of a bag with five colors of skittles
class SkittlesBag {
public:
  //constructors
  SkittlesBag(); //0 count of each color of skittle
  SkittlesBag(int r, int y, int g, int o, int p);

  //accessors and mutators
  int size() const; //gets the number of skittles in the bag
  int count(char c) const; //gets the count of a designated colored skittle
  void printHistogram() const;
  void addOne(char c); //adds one skittle to a designated color
  void eat(int eaten, char c); //eats a designated amount of one designated color of skittles
  void evenOut(); //makes every color of skittles equal in count
  void pourInDish(SkittlesDish& dish); //pours a dish of skittles into the bag

  //operators overloaded as members
  void operator +=(SkittlesBag& rhs); //adds rhs bag to lhs bag

private:
  int red;
  int yellow;
  int green;
  int orange;
  int purple;
};

//operators overloaded as non-members
bool operator ==(const SkittlesBag& lhs, const SkittlesBag& rhs); //returns true if lhs and rhs bags are equal

#endif
