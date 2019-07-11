#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main(){
    int num[10] = {};
    for(int i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    int temp;
    bool flag = false;
    for(int i = 1; i < 10; i++){
        while(num[i] != 0){
            printf("%d", i);
            num[i]--;
            temp = i;
            flag = true;
            break;
        }
        if(flag)
            break;
    }
    while(num[0] != 0){
        printf("%d", 0);
        num[0]--;
    }
    for(int j = 1; j < 10; j++){
        while(num[j] != 0){
            printf("%d", j);
            num[j]--;
        }
    }
    return 0;
}