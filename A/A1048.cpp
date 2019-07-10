#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int hashtable[100010] = {};
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int temp;
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        hashtable[temp]++;
    }
    for(int i = 1; i < M; i++){
        if(hashtable[i] && hashtable[M - i]){
            if(i == M - i && hashtable[i] <= 1)
                continue;
            printf("%d %d\n", i, M - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}