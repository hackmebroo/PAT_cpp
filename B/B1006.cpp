#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, temp, in;
    cin >> in;
    temp = in / 100;
    for(i=0;i<temp;i++)
        printf("B");
    in %= 100;
    temp = in / 10;
    for(i=0;i<temp;i++)
        printf("S");
    in %= 10;
    for(i=0;i<in;i++)
        printf("%d", i + 1);
    return 0;
}