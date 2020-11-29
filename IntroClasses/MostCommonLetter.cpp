#include <iostream>

using namespace std;

char MostCommonLetter(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    int same[i];
    for(int j=0;j<i;j++){
        same[j]=0;
        for(int k=0;k<i;k++){
            if(arr[j]==arr[k]){
                same[j]++;
            }
        }
        if(arr[j]==' '){
            same[j]=0;
        }
    }
    int index=0;
    int total=same[0];
    for(int j=1;j<i;j++){
        if(total<same[j]){
            total=same[j];
            index=j;
        }
    }
    char most=arr[index];
    return most;
}

int main(){
    char arr[64]="Santa Clara University";
    char most=MostCommonLetter(arr);
    cout<<most<<endl;
}
