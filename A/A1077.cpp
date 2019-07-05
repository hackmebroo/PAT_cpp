#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    getchar();
    char in[N][260];
    for(int i = 0; i < N; i++){
        cin.getline(in[i], 260);
    }
    int len[N], min = 260;
    for(int i = 0; i < N; i++){
        len[i] = strlen(in[i]);
        if(len[i] < min)
            min = len[i];
    }
    int count = 0;
    for(int j = 0; j < min; j++){
        int sign = 0;
        for(int i = 1; i < N; i++){
            if(in[i][len[i] - j - 1] == in[0][len[0] - j - 1])
                continue;
            else {
                sign++;
                break;
            }
        }
        if(sign == 0)
            count++;
        else 
            break;
    }
    if(count == 0)
        printf("nai");
    else {
        for(int i = len[0] - count; i < len[0]; i++){
            printf("%c", in[0][i]);
        }
    }
    return 0;
}