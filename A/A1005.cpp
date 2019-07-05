#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[110];
    scanf("%s", str);
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += str[i] - '0';
    }
    char change[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int count = 1, out[110] = {}, p = 0;
    while(sum >= 10){
        out[p] = sum % 10;
        sum /= 10;
        p++;
    }
    out[p] = sum;
    for(int i = p; i >= 0; i--){
        printf("%s", change[out[i]]);
        if(i != 0)
            printf(" ");
    }
    return 0;
}
