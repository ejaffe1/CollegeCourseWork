#include <iostream>

using namespace std;

// keeps track of count of a monochromatic dish of skittles
class SkittlesDish {
public:
  // constructors
  SkittlesDish(); // 0 red skittles
  SkittlesDish(int initialCount, string color);

  // accessors and mutators
  int getCount() const;
  string getColor() const;
  void addSkittles(int numToAdd); // increase the count by numToAdd
  void eatSkittles(int numToEat); // decrement count, or do nothing if count<num

  // operators overloaded as members or nonmember friends
  bool operator ==(const SkittlesDish& rhs) const; //# and color
  friend bool operator <(const SkittlesDish& lhs, const SkittlesDish& rhs); //#
  //void operator +=(SkittlesDish& rhs); // += as member function
private:
  int count;
  string color;
};

// += as nonmember/nonfriend: if same color, pour contents of rhs into lhs
SkittlesDish operator +=(SkittlesDish& lhs, SkittlesDish& rhs);

#endif
