#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, j, a, b, max1, max2;
    double A[1001] = {}, B[1001] = {}, out[2010] = {};
    cin >> a;
    int temp1;
    double temp2;
    for(i=0;i<a;i++){
        cin >> temp1 >> temp2;
        if(i == 0)
            max1 = temp1;
        A[temp1] = temp2;
    }
    cin >> b;
    for(i=0;i<b;i++){
        cin >> temp1 >> temp2;
        if(i == 0)
            max2 = temp1;
        B[temp1] = temp2;
    }
    double temp;
    for(i=0;i<=max1;i++){
        for(j=0;j<=max2;j++){
            temp = B[j] * A[i];
            out[i + j] += temp;
        }
    }
    int count = 0;
    for(i=max1 + max2;i>=0;i--){
        if(out[i] != 0)
            count++;
    }
    printf("%d",count);
    for(i=max1 + max2;i>=0;i--){
        if(out[i] != 0)
            printf(" %d %.1f", i, out[i]);
    }
    return 0;
}
