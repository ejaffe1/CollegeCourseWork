/*
Base Class: drink
Derived Class: Smoothie

The base class is a general template for any type of drink. The smoothie class
inherits the drink class and then provides a template for any type of smoothie.
This is demonstrating the idea of inheritance because the smoothie class uses all the
essential parts of the drink class. Without the drink class, the smoothie class could not
create objects that model a smoothie drink. The drink class has essential variables to a
drink that cover the drink's name, the size of the drink, and the calories of the drink.
The smoothie class includes new additional member variables to account for a main ingredient,
the sugar count, and the consistency of the smoothie. The smoothie class uses both drinks
variables and it's own to create the smoothie object. There is also a new function in
the smoothie class that mixes the smoothie to make it smoother. The smoothie class also
redefines the function consume drink to now account for the new member variables. Overall,
the smoothie class uses everything in the drink class and in its own to create smoothie objects.

*/

#include <iostream>
#include <string>
using namespace std;

class drink{
public:
  //Constructors
  drink():drinkName_("--"), size_(0),calories_(0){}
  drink(string dn, int size, int cal):drinkName_(dn), size_(size),calories_(cal){}
  //Accessors
  string getDrinkName(){return drinkName_;}
  int getSize(){return size_;};
  int getCalories(){return calories_;};
  //Mutators
  void consumeDrink(); //consumes the drink and sets int varaibles to 0
  void changeSize(int newSize); //increases or decreases the size and changes the calories depending on the size
  void addCalories(int calInc); //adds an amount of calories to the drink

private:
    string drinkName_; //the name of the drink
    int size_; //the size of the drink in ounces
    int calories_; //the amount of calories in the drink
};

ostream& operator <<(ostream& out, drink& b);

class Smoothie: public drink{
public:
  //constructors
  Smoothie():mainIngredient_("None"), sugar_(0), drink(){}
  Smoothie(string dn, int size, int cal, string ing, int sugar, int consis): drink(dn,size,cal),
  mainIngredient_(ing), sugar_(sugar), consistency_(consis){}
  //Accessors
  string getMainIngredient(){return mainIngredient_;}
  int getSugarCount(){return sugar_;}
  int getConsistency(){return consistency_;}
  //Mutators
  void mixSmoothie(){if(consistency_<5){consistency_++;}} //this mixes the smoothie and increases the consistency
  void sweeten(int sugarIncrease); //sweetens the smoothie by adding sugar
  void consumeDrink(); //this is a redefined function to set int variables to 0
private:
  string mainIngredient_; //the main ingredient in the smoothie
  int sugar_; //the ammount of sugar in grams
  int consistency_; //the consistency of the smoothie on a scale from 0-5, 0 being most chunky and 5 being most smooth
};

ostream& operator <<(ostream& out, Smoothie& b);

int main(){
  drink water("Water",10,0);
  Smoothie strbry("Strawberry Smoothie", 16, 400, "strawberry", 25, 3);
  cout<<"\n"<<water<<endl;
  cout<<strbry<<endl;
  cout<<"How many calories are in this smoothie?"<<endl;
  cout<<strbry.getCalories()<<" calories"<<endl;
  cout<<"Wow that's quite a bit. Let's decrease the size."<<endl;
  cout<<"Decreasing "<<strbry.getDrinkName()<<" size from "<<strbry.getSize()<<" ounces to 10 ounces."<<endl;
  strbry.changeSize(10);
  cout<<"How many calories now?"<<endl;
  cout<<"Calories: "<<strbry.getCalories()<<endl;
  cout<<"That's better, but the consistency is a little thick, lets mix it."<<endl;
  strbry.mixSmoothie();
  cout<<"New Consistency: "<<strbry.getConsistency()<<endl;
  cout<<"The smoothie could be a little sweeter, lets sweeten it."<<endl;
  strbry.sweeten(4);
  cout<<"New Sugar Count: "<<strbry.getSugarCount()<<" grams"<<endl;
  cout<<"I think I am ready to drink this... gulp gulp."<<endl;
  strbry.consumeDrink();
  cout<<"Is there any sugar left in there?"<<endl;
  cout<<"Sugar count: "<<strbry.getSugarCount()<<" grams"<<endl;
  cout<<"Wow! I need to drink some water now..."<<endl;
  water.consumeDrink();
  cout<<"Let's see whats left of my water cup and smoothie."<<endl;
  cout<<water<<endl;
  cout<<strbry<<endl;
  return 0;
}

void drink::consumeDrink(){
  size_=0;
  calories_=0;
}
void drink::changeSize(int newSize){
  size_=newSize;
  if(calories_!=0){
    calories_= newSize*25;
  }
}

void drink::addCalories(int calInc){
  calories_+=calInc;
}

ostream& operator <<(ostream& out, drink& b){
  out<<"Drink Name: "<<b.getDrinkName()<<endl;
  out<<"Size: "<<b.getSize()<<" ounces"<<endl;
  out<<"Calories: "<<b.getCalories()<<endl;
  return out;
}

void Smoothie::sweeten(int sugarIncrease){
  sugar_+=sugarIncrease;
  addCalories(sugarIncrease*20);
}

void Smoothie::consumeDrink(){
  drink::consumeDrink();
  sugar_=0;
  consistency_=0;
}

ostream& operator <<(ostream& out, Smoothie& b){
  out<<"Drink Name: "<<b.getDrinkName()<<endl;
  out<<"Size: "<<b.getSize()<<" ounces"<<endl;
  out<<"Calories: "<<b.getCalories()<<endl;
  out<<"Main Ingredient: "<<b.getMainIngredient()<<endl;
  out<<"Sugar: "<<b.getSugarCount()<<" grams"<<endl;
  out<<"Consistency: "<<b.getConsistency()<<endl;
  return out;
}
