#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int hashtable[110] = {};
int main(){
    int num;
    scanf("%d", &num);
    int temp;
    for(int i = 0; i < num; i++){
        scanf("%d", &temp);
        hashtable[temp]++;
    }
    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &temp);
        printf("%d", hashtable[temp]);
        if(i != K - 1)
            printf(" ");
    }
    return 0;
}