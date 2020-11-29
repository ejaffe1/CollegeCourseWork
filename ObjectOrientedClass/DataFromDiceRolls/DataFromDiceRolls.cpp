#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int N_ROLLS = 200; // how many rolls to simulate
const string DATA_FILENAME = "data.txt";
const string HIST_FILENAME = "hist.txt";

int getRoll() {return (rand()%6+rand()%6+2);}

void simulateAndRecord();

void produceHistogram();

void writeLineOfStars(int rolls[], int nRolls, int val, ostream& out);

int main() {
  simulateAndRecord();
  produceHistogram();
  return 0;
}

void simulateAndRecord() {
    ofstream datafile(DATA_FILENAME); // open DATA_FILENAME
    for (int i=0; i<N_ROLLS; i++) {
        datafile << getRoll() << endl; // simulate 1 roll and output it to datafile
    }
    datafile.close(); // close the file
}

void produceHistogram() {
    ifstream datafile(DATA_FILENAME);
    ofstream histfile(HIST_FILENAME);
    int rolls[N_ROLLS];
    int i=0;
    while(!datafile.eof()){
        datafile>>rolls[i];
        i++;
    }
    for(int j=2;j<13;j++){
        writeLineOfStars(rolls, N_ROLLS, j, histfile);
    }
    datafile.close();
    histfile.close();
}

void writeLineOfStars(int rolls[], int nRolls, int val, ostream& out){
  out<<val<<" : ";
  for(int i=0; i<nRolls; i++){
      if(rolls[i]==val){
          out<< "*";
        }
    }
    out << endl;
}
