#include "skittlesbag.h"

SkittlesBag::SkittlesBag():red(0),yellow(0),green(0),orange(0),purple(0){}

SkittlesBag::SkittlesBag(int r, int y, int g, int o, int p){
  red=r;
  yellow=y;
  green=g;
  orange=o;
  purple=p;
}

int SkittlesBag::size() const{return red+yellow+green+orange+purple;}

int SkittlesBag::count(char c) const{
  switch(c){
    case('r'):
      return red;
    case('y'):
      return yellow;
    case('g'):
      return green;
    case('o'):
      return orange;
    case('p'):
      return purple;
    default:
      return 0;
  }
}

void SkittlesBag::printHistogram() const{
  cout<<"r: ";
  for(int i=0;i<red;i++){
    cout<<"*";
  }
  cout<<"\ny: ";
  for(int i=0;i<yellow;i++){
    cout<<"*";
  }
  cout<<"\ng: ";
  for(int i=0;i<green;i++){
    cout<<"*";
  }
  cout<<"\no: ";
  for(int i=0;i<orange;i++){
    cout<<"*";
  }
  cout<<"\np: ";
  for(int i=0;i<purple;i++){
    cout<<"*";
  }
  cout<<endl;
}

void SkittlesBag::addOne(char c){
  switch(c){
    case('r'):
      red++;
      break;
    case('y'):
      yellow++;
      break;
    case('g'):
      green++;
      break;
    case('o'):
      orange++;
      break;
    case('p'):
      purple++;
      break;
  }
}

void SkittlesBag::eat(int eaten, char c){
  switch(c){
    case('r'):
      if(red<eaten){
        red=0;
      }else{
        red-=eaten;
      }
      break;
    case('y'):
      if(yellow<eaten){
        yellow=0;
      }else{
        yellow-=eaten;
      }
      break;
    case('g'):
      if(green<eaten){
        green=0;
      }else{
        green-=eaten;
      }
      break;
    case('o'):
      if(orange<eaten){
        orange=0;
      }else{
        orange-=eaten;
      }
      break;
    case('p'):
      if(purple<eaten){
        purple=0;
      }else{
        purple-=eaten;
      }
      break;
  }
}

void SkittlesBag::evenOut(){
  int num[5]={red,yellow,green,orange,purple};
  int redEat,yelEat,greenEat,orEat,purEat;
  int lowest=num[0];
  for(int i=1;i<5;i++){
    if(num[i]<lowest){
      lowest=num[i];
    }
  }
  redEat=num[0]-lowest;
  yelEat=num[1]-lowest;
  greenEat=num[2]-lowest;
  orEat=num[3]-lowest;
  purEat=num[4]-lowest;
  red=lowest;
  yellow=lowest;
  green=lowest;
  orange=lowest;
  purple=lowest;
  cout<<redEat<<" red eaten\n"<<yelEat<<" yellow eaten\n"<<greenEat<<" green eaten\n"<<
  orEat<<" orange eaten\n"<<purEat<<" purple eaten\n"<<lowest<<" of each remaining.\n";
}

void SkittlesBag::pourInDish(SkittlesDish& dish){
  string color=dish.getColor();
  int count=dish.getCount();
  if(color=="red"){
      red+=count;
      dish.eatSkittles(count);
    }
  if(color=="yellow"){
      yellow+=count;
      dish.eatSkittles(count);
    }
  if(color=="green"){
      green+=count;
      dish.eatSkittles(count);
    }
  if(color=="orange"){
      orange+=count;
      dish.eatSkittles(count);
    }
  if(color=="purple"){
    purple+=count;
    dish.eatSkittles(count);
  }
}

void SkittlesBag::operator +=(SkittlesBag& rhs){
  red+=rhs.red;
  yellow+=rhs.yellow;
  green+=rhs.green;
  orange+=rhs.orange;
  purple+=rhs.purple;
  rhs.red=0;
  rhs.yellow=0;
  rhs.green=0;
  rhs.orange=0;
  rhs.purple=0;
}

bool operator ==(const SkittlesBag& lhs, const SkittlesBag& rhs){
  return lhs.count('r')==rhs.count('r')&&lhs.count('y')==rhs.count('y')&&
  lhs.count('g')==rhs.count('g')&&lhs.count('o')==rhs.count('o')&&
  lhs.count('p')==rhs.count('p');
}
