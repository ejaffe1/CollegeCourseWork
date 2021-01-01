#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const string INFILE = "records.txt";

struct Student{
  string name;
  string password;
  string gpa;
  string id;
};

map<string,string> ReadIn();

int main() {
  map<string,string> students=ReadIn();
  while(true){
    cout<<"Enter an ID number (enter 0 to quit): ";
    string idNum;
    cin>>idNum;
    if(idNum=="0"){
      break;
    }
    cout<<"Enter password: ";
    string passwordIn;
    cin>>passwordIn;
    if(students[idNum]==passwordIn){
      string name=students[passwordIn];
      cout<<"Name: "<<students[passwordIn]<<endl;
      cout<<"GPA: "<<students[name]<<endl;
    }else{
      cout<<"That was the wrong password."<<endl;
    }
  }
  cout<<"Goodbye!"<<endl;
  return 0;
}

map<string,string> ReadIn(){
  ifstream input;
  input.open(INFILE);
  if(input.fail()){
    cout<<"File failed to open"<<endl;
  }
  map<string,string> students;
  Student s[6];
  for(int i=0;i<6;i++){
    input>>s[i].name;
    input>>s[i].id;
    input>>s[i].password;
    input>>s[i].gpa;
  }
  for(int i=0;i<6;i++){
    students[s[i].id]=s[i].password;
    students[s[i].password]=s[i].name;
    students[s[i].name]=s[i].gpa;
  }
  input.close();
  return students;
}
