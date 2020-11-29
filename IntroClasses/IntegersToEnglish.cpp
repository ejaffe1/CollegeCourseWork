#include <iostream>

using namespace std;

void IntToEnglish(int n){
   while(n>0){
       int a=n%10;
       n=n/10;
       switch (a){
           case 0:
               cout<<"Zero ";
               break;
           case 1:
               cout<<"One ";
               break;
           case 2:
               cout<<"Two ";
               break;
           case 3:
               cout<<"Three ";
               break;
           case 4:
               cout<<"Four ";
               break;
           case 5:
               cout<<"Five ";
               break;
           case 6:
               cout<<"Six ";
               break;
           case 7:
               cout<<"Seven ";
               break;
           case 8:
               cout<<"Eight ";
               break;
           case 9:
               cout<<"Nine ";
               break;
       }
   }
   cout<<endl;
}

void UserIntToEnglish(){
   int n=1;
   while(n>0){
       cout<<"Please enter a positive integer."<<endl;
       cin>>n;
       IntToEnglish(n);
       if(n<=0){
           break;
       }
   }
}

int main(){
   UserIntToEnglish();
}
