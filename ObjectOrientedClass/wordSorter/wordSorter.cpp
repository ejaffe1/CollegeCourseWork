#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
using namespace std::chrono; // for timing experiments

const int EXPERIMENT = 1; // change this as you test your algorithms (1-3)
const string INFILE = "quickbrownfox.txt"; //"don_quixote.txt"; // test with DQ
const string OUTFILE = "output.txt"; // don't change this!

void timedExperiment(string filename, int exp);
void readWithVector1(string filename);
void readWithVector2(string filename);
void readWithSet(string filname);

// starts a timed experiment based on default values or command line arguments
int main(int argc, char** argv) {
  if (argc<2) timedExperiment(INFILE,EXPERIMENT); // test according to constants
  else timedExperiment(argv[1],stoi(argv[2])); // or use command line arguments
  return 0;
}

// runs specified experiment on the specified filename and reports the time
void timedExperiment(string filename, int exp) {
  auto start = high_resolution_clock::now();
  switch (exp) {
    case 1: readWithVector1(filename); break;
    case 2: readWithVector2(filename); break;
    case 3: readWithSet(filename); break;
    default: cout << "Invalid experiment number specified\n"; return;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count()/1000000.0 << " seconds for alg " << exp <<
    " to process " << filename << endl;
}

// TODO: implement these experiments!

void readWithVector1(string filename) {
  ifstream input;
  ofstream out;
  input.open(filename);
  if(input.fail()){
    cout<<"File failed to open"<<endl;
  }
  out.open(OUTFILE);
  if(out.fail()){
    cout<<"File failed to open"<<endl;
  }
  vector<string> inputFile;
  string s;
  int counter=1;
  input>>s;
  inputFile.push_back(s);
  while(!input.eof()){
    bool check=false;
    input>>s;
    for(auto i=0;i<counter;i++){
      if(inputFile[i]==s){
        check=true;
        break;
      }
    }
    if(check==false){
      inputFile.push_back(s);
      counter++;
    }
  }
  sort(inputFile.begin(),inputFile.end());
  for(auto i=0;i<inputFile.size();i++){
    out<<inputFile[i]<<endl;
  }
  input.close();
  out.close();
}

void readWithVector2(string filename) {
  ifstream input;
  ofstream out;
  input.open(filename);
  if(input.fail()){
    cout<<"File failed to open"<<endl;
  }
  out.open(OUTFILE);
  if(out.fail()){
    cout<<"File failed to open"<<endl;
  }
  vector<string> inputFile;
  string s;
  while(!input.eof()){
    input>>s;
    inputFile.push_back(s);
  }
  sort(inputFile.begin(),inputFile.end());
  string check;
  for(auto i=0;i<inputFile.size();i++){
    if(inputFile[i]!=check){
      out<<inputFile[i]<<endl;
      check=inputFile[i];
    }
  }
  input.close();
  out.close();
}

void readWithSet(string filename) {
  ifstream input;
  ofstream out;
  input.open(filename);
  if(input.fail()){
    cout<<"File failed to open"<<endl;
  }
  out.open(OUTFILE);
  if(out.fail()){
    cout<<"File failed to open"<<endl;
  }
  set<string> inputFile;
  string s;
  while(!input.eof()){
    input>>s;
    inputFile.insert(s);
  }
  for(auto i=inputFile.begin();i!=inputFile.end();i++){
    out<<*i<<endl;
  }
  input.close();
  out.close();
}
