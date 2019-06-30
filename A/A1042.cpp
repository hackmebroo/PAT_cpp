#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, j, times, ran[54], out[54], temp[54];
    cin >> times;
    for(i=0;i<54;i++)
        cin >> ran[i];
    //输入random数组
    for(i=0;i<54;i++){
        out[i] = i + 1;
        temp[i] = i + 1;
    }
    //初始化牌组
    for(i=0;i<times;i++){
        for(j=0;j<54;j++){
            out[ran[j] - 1] = temp[j];
        }
        for(j=0;j<54;j++){
            temp[j] = out[j];
        }
    }
    //shuffling
    for(i=0;i<54;i++){
        if(out[i] <=13)
            printf("S%d", out[i]);
        else if(out[i] <=26)
            printf("H%d", out[i] - 13);
        else if(out[i] <= 39)
            printf("C%d", out[i] - 26);
        else if(out[i] <= 52)
            printf("D%d", out[i] - 39);
        else
            printf("J%d", out[i] - 52);
        if(i != 53)
            printf(" ");
    }
    return 0;
}