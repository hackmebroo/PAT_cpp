#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    long int a[N][3], temp;
    int i, j;
    for(i=0;i<N;i++){
        for(j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    int out[N];
    for(i=0;i<N;i++){
        temp = a[i][0] + a[i][1];
        if(temp > a[i][2])
            out[i] = 1;
        else
            out[i] = 0;
    }
    for(i=0;i<N;i++){
        printf("Case #%d: ",i+1);
        if(out[i] == 0)
            printf("false\n");
        else
            printf("true\n");
    }
    return 0;
}