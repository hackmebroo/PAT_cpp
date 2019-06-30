#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, N;
    cin >> N;
    long long a, b, c, temp;
    for(i=0;i<N;i++){
        cin >> a >> b >> c;
        temp = a + b;
        if(a > 0 && b > 0 && temp < a)
            printf("Case #%d: true",i + 1);
        else if(a < 0 && b < 0 && temp > a)
            printf("Case #%d: false",i + 1);
        else{
            if(temp > c)
                printf("Case #%d: true",i + 1);
            else
                printf("Case #%d: false",i + 1);
        }
        if(i != N - 1)
            printf("\n");
    }  
}