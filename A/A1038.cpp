#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct digit{
    char num[10] = {};
}input[10010];
bool cmp(digit a, digit b){
    int len1 = strlen(a.num), len2 = strlen(b.num);
    char temp1[10] = {}, temp2[10] = {};
    strcpy(temp1, a.num);
    strcpy(temp2, b.num);
    if(len1 < len2){
        for(int i = len1; i < len2; i++){
            temp1[i] = temp2[i - len1];
        }
    }
    else if(len1 > len2){
        for(int i = len2; i < len1; i++){
            temp2[i] = temp1[i - len2];
        }
    }
    for(int i = 0; i < len1 || i < len2; i++){
        if(temp1[i] != temp2[i]) return temp1[i] < temp2[i];
    }
    //填充字符串    
    return temp1 < temp2;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", input[i].num);
    }
    sort(input, input + N, cmp);
    bool flag = false;
    int p = 0;
    while(!flag && p < N){
        int len = strlen(input[p].num);
        for(int i = 0; i < len; i++){
            if(input[p].num[i] != '0'){
                for(int j = i; j < len; j++){
                    printf("%c", input[p].num[j]);
                    flag = true;
                }
                break;
            }
        }
        if(flag)
            break;
        else 
            p++;
    }
    if(!flag){
        printf("0");
        return 0;
    }
    for(int i = p + 1; i < N; i++){
        if(flag)
            printf("%s", input[i].num);
    }
    return 0;
}