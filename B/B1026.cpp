#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    long int a, b, c;
    scanf("%ld%ld",&a,&b);
    c = b - a;
    if((c % 100) >= 50){
        c /= 100;
        c += 1;
    }
    else
        c /= 100;

    printf("%02d:%02d:%02d",c / 3600, (c % 3600) / 60, c % 60);
    return 0;

}