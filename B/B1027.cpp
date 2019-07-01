#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    int i, j, N, temp, row, max, rest;
    cin >> N;
    for(i=1;i<40;i++){
        temp = 2 * i * i - 1;
        if(temp > N){
            row = i - 1;
            rest = N - (2 * (i - 1) * (i - 1) - 1);
            break;
        }
        else
            continue;
    }
    max = 2 * row - 1;
    char sign;
    cin >> sign;
    for(i=0;i<row;i++){
        for(j=0;j<i;j++)
            printf(" ");
        for(j=0;j<max;j++)
            printf("%c",sign);
        max -= 2;
        printf("\n");
    }
    max += 4;
    for(i=0;i<row-1;i++){
        for(j=0;j<row-2-i;j++)
            printf(" ");
        for(j=0;j<max;j++)
            printf("%c",sign);
        max += 2;
        printf("\n");
    }
    printf("%d", rest);

    return 0;
}