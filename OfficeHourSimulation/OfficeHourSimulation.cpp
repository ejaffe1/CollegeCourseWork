#include <iostream>
#include <string>
#include<queue>
#include<map>
#include<fstream>

using namespace std;

struct Student{
  int servicetime;
  int priority;
  string topic;
};
bool operator <(Student lhs,Student rhs);
void OfficeHour(int& avrgwait, int& avrgserv, int& overtime, multimap<int,string>& stutopics, int& numOfStu);
void OfficeHourTest();

int main(){
  srand(time(0));
  OfficeHourTest();
  return 0;
}

bool operator <(Student lhs,Student rhs){
  if(lhs.priority<rhs.priority){return true;}
  return false;
}

void OfficeHour(int& avrgwait, int& avrgserv, int& overtime, multimap<int,string>& stutopics, int& numOfStu){
  Student students[100];
  int count=0;
  int waittime=0;
  string topics[10];
  topics[0]="Strings";
  topics[1]="Arrays";
  topics[2]="Structures";
  topics[3]="Classes";
  topics[4]="Stacks";
  topics[5]="Queues";
  topics[6]="Trees";
  topics[7]="Heaps";
  topics[8]="B-Trees";
  topics[9]="BSTs";
  for(int t=0;t<60;t++){
    if(20>rand()%100){
      students[count].servicetime=rand()%15;
      students[count].priority=rand()%10;
      count++;
      if(5>rand()%100){
        students[count].servicetime=rand()%15;
        students[count].priority=rand()%10;
        count++;
        if(1>rand()%100){
          students[count].servicetime=rand()%15;
          students[count].priority=rand()%10;
          count++;
        }
      }
    }
  }
  int wait[count];
  int serv[count];
  priority_queue<Student> ohstudents;
  for(int i=0;i<count;i++){
    ohstudents.push(students[i]);
    int topicnum=rand()%10;
    students[i].topic=topics[topicnum];
  }
  int i=0;
  while(!ohstudents.empty()){
    serv[i]=ohstudents.top().servicetime;
    waittime+=ohstudents.top().servicetime;
    wait[i]=waittime;
    ohstudents.pop();
    i++;
  }
  for(int k=0;k<count;k++){
    avrgwait+=wait[k];
    avrgserv+=serv[k];
    stutopics.insert(make_pair(k+1,students[k].topic));
  }
  avrgwait/=count;
  avrgserv/=count;
  if(waittime>60){
    overtime=waittime-60;
  }else{
    overtime=waittime;
  }
  numOfStu=count;
}

void OfficeHourTest(){
  cout<<"100 Runs of the Office Hour Simulation: "<<endl;
  int wait=0;
  int serv=0;
  int overtime=0;
  int wait100[100];
  int serv100[100];
  int overtime100[100];
  string stutopics[100];
  int count=0;
  int totstu=0;
  multimap<int,string> topics;
  for(int i=0;i<100;i++){
    OfficeHour(wait,serv,overtime,topics,count);
    wait100[i]=wait;
    serv100[i]=serv;
    overtime100[i]=overtime;
    if(count>totstu){totstu=count;}
  }
  int avwait=0;
  int avserv=0;
  int avovertime=0;
  for(int i=0;i<100;i++){
    avwait+=wait100[i];
    avserv+=serv100[i];
    avovertime+=overtime100[i];
  }
  avwait/=100;
  avserv/=100;
  avovertime/=100;
  cout<<"Average Wait: "<<avwait<<" minutes"<<endl;
  cout<<"Average Service Time: "<<avserv<<" minutes"<<endl;
  cout<<"Average Overtime: "<<avovertime<<" minutes"<<endl;
  ofstream myfile;
  ofstream myfile2;
  ofstream myfile3;
  myfile.open("topics.txt");
  myfile2.open("sorted.txt");
  myfile3.open("search.txt");
  if(!myfile.is_open()){cout<<"File failed to open :("<<endl;}
  myfile<<"Professors Report: "<<endl;
  int prev=0;
  for(multimap<int,string>::const_iterator it=topics.begin(); it!=topics.end();++it){
    if(prev!=it->first){
      myfile<<"Student "<<it->first<<" came to office hours "<<topics.count(it->first)<<" times.\n"<<"Topics: "<<endl;
      myfile2<<"Student "<<it->first<<": "<<topics.count(it->first)<<" visits."<<endl;
    }
    myfile<<it->first<<'\t'<<it->second<<'\n';
    prev=it->first;
  }
  int student;
  cout<<"Please enter which student you would like to access (ENTER INTEGER): "<<endl;
  cin>>student;
  for(multimap<int,string>::const_iterator it=topics.begin(); it!=topics.end();++it){
    if(it->first==student){
      if(prev!=it->first){
        myfile3<<"Student "<<it->first<<" came to office hours "<<topics.count(it->first)<<" times.\n"<<"Topics: "<<endl;
      }
      myfile3<<it->first<<'\t'<<it->second<<'\n';
      prev=it->first;
    }
  }
  myfile3<<endl;
  string topic;
  cout<<"Please enter which topic you would like to access (ENTER STRING, FIRST LETTER CAP; EX: Stacks): "<<endl;
  cin>>topic;
  myfile3<<"Students who asked about "<<topic<<endl;
  for(multimap<int,string>::const_iterator it=topics.begin(); it!=topics.end();++it){
    if(it->second==topic){
      myfile3<<it->first<<'\t'<<it->second<<'\n';
    }
  }
  myfile.close();
  myfile2.close();
  myfile3.close();
}
