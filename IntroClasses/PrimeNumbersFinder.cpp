#include <iostream>

using namespace std;

void FindPrimes(int prime[], int len){
   int prime_num=2;
   int i=0;
   while(i<len){
       int prime_check=1;
       for(int j=2;j<prime_num;j++){
           if(prime_num%j==0){
               prime_check=0;
               break;
           }
       }
       if(prime_check!=0){
           prime[i]=prime_num;
           i++;
       }
       prime_num++;
   }
   for(int i=0;i<len;i++){
       cout<<prime[i]<<" ";
   }
   cout<<endl;
}

int main(){
   int len;
   cout<<"Please enter a length."<<endl;
   cin>>len;
   int prime[len];
   FindPrimes(prime, len);
}
