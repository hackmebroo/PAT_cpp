#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    long int a, b;
    int a1, b1;
    cin >> a >> a1 >> b >> b1;
    int i, temp, count1 = 0 , count2 = 0;
    for(i=1;i<11;i++){
        if(a >= 10){
            temp = a % 10;
            if(temp == a1)
                count1++;
            a /= 10;
        }
        else{
            if(a == a1)
                count1++;
            break;
        }
    }
    for(i=1;i<11;i++){
        if(b >= 10){
            temp = b % 10;
            if(temp == b1)
                count2++;
            b /= 10;
        }
        else{
            if(b == b1)
                count2++;
            break;
        }
    }

    double out1 = 0, out2 = 0;
    for(i=0;i<count1;i++){
        out1 += double(a1) * pow(10.0, double(i));
    }
    for(i=0;i<count2;i++){
        out2 += double(b1) * pow(10.0, double(i));
    }
    printf("%.0f",out1 + out2);
    return 0;
}