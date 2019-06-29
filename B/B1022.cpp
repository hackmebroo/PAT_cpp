#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    int a, b, sum;
    int c;
    cin >> a >> b >> c;
    sum = a + b;
    int count = 0, temp1;
    int i=1;
    while(sum > 0){
        temp1 = pow(double(c),double(i));
        sum /= temp1;
        count++;
    }
    //求出进制数的最高次数
    sum = a + b;
    if(sum == 0)
        count = 1;
    int out[count];
    double temp;
    for(i=0;i<count;i++){
        temp = pow(double(c),double((count - i - 1)));
        out[i] = sum / temp;
        sum -= temp * out[i];
    }
    for(i=0;i<count;i++){
        printf("%d",out[i]);
    }
    return 0;
}