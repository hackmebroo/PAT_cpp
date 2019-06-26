#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int c = a + b;
    if(c<0) 
        cout<<'-';
    c=abs(c);
    char s[20];
    sprintf(s,"%d",c);
    int len=strlen(s);
    int m=len/3,n=len%3,start=0;
    if(n==0){
        cout<<s[0]<<s[1]<<s[2];
        start=3;
        m--;
    }
    else if(n==1){
        cout<<s[0];
        start=1;
    }
    else if(n==2){
        cout<<s[0]<<s[1];
        start=2;
    }
    while(m!=0){
        cout<<',';
        cout<<s[start]<<s[start+1]<<s[start+2];
        start+=3;
        m--;    
    }
    return 0;
}


