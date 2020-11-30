#include <iostream>
#include <string>
using namespace std;

class MazeRacer {
public:
    MazeRacer():name("None"),x(0),y(0){}
    MazeRacer(string n, int xin, int yin);
    string getName(){return name;}
    int getx(){return x;}
    int gety(){return y;}
    int getMoves(){return moves;}
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
private:
    string name;
    int x;
    int y;
    int moves;
};

void moveRacer(MazeRacer& racer);
void checkDestination(MazeRacer racer, int tx, int ty);

int main() {
    cout << "Enter a name for the first maze competitor: ";
    string racername;
    cin>>racername;
    MazeRacer racer1(racername, 0, 0); // first get name then construct racer1 accordingly
    cout <<racer1.getName()<<" will start at (0,0).\n";
    cout << "Enter a name for the second maze competitor: ";
    string racer2name;
    cin>>racer2name;
    int racer2x,racer2y;
    cout << "Enter starting coordinates for "<<racer2name<<": ";
   // get name and coordinates; construct racer2 accordingly
    cin>>racer2x>>racer2y;
    MazeRacer racer2(racer2name,racer2x,racer2y);

    cout << "Enter the target coordinates: ";
    int tx, ty; // populate target coordinates
    cin>>tx>>ty;

    // implement moveRacer to get move sequence from user
    moveRacer(racer1);
    moveRacer(racer2);

    // implement checkDestination to see whether targets are reached
    checkDestination(racer1, tx, ty);
    checkDestination(racer2, tx, ty);
    return 0;
}

// get move sequence from user and move racer accordingly
void moveRacer(MazeRacer& racer) {
  cout << "Enter a sequence of moves (LRUD) for "<<racer.getName()<<":\n";
  string seq;
  cin >> seq;
  
// move racer depending on the direction specified by seq.at(i)
  for (int i=0; i<seq.length(); i++) {
      switch(seq[i]){
          case ('L'):
              racer.moveLeft();
              break;
          case ('R'):
              racer.moveRight();
              break;
          case ('U'):
              racer.moveUp();
              break;
          case ('D'):
              racer.moveDown();
              break;
      }
  }
}

// report whether racer is at (tx,ty)
void checkDestination(MazeRacer racer, int tx, int ty) {
  if ((tx==racer.getx())&&(ty==racer.gety())) {
    cout << racer.getName()<<" was at the target after "<< racer.getMoves()<<" moves\n";
  } else {
    cout << racer.getName()<<" was not at the target after "<< racer.getMoves()<<" moves\n";
  }
}

MazeRacer::MazeRacer(string n, int xin, int yin){
        name=n;
        x=xin;
        y=yin;
        moves=0;
}

void MazeRacer::moveLeft(){
    x--;
    moves++;
}
void MazeRacer::moveRight(){
    x++;
    moves++;
}
void MazeRacer::moveUp(){
    y++;
    moves++;
}
void MazeRacer::moveDown(){
    y--;
    moves++;
}
