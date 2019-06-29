#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int i;
    char in[82] = {};
    for(i=0;i<83;i++){
        if(i == 0)
            in[0] = ' ';
        else{
            scanf("%c",&in[i]);
            if(in[i] == '\n'){
                in[i] = 0;
                break;
            }
        }
    }
    int p = 0, j, k;
    char temp[80] = {};
    for(i=0;i<82;i++){
        if(in[81 - i] == 0)
            continue;
        else if(in[81 - i] == ' '){
            k = p;
            for(j=0;j<k;j++){
                printf("%c",temp[p - 1]);
                temp[p - 1] = 0;
                p--;
            }//打印字符
            p = 0;
            if(i != 81)
                printf(" ");
        }
        else{
            temp[p] = in[81 - i];
            p++;
        }
    }
    return 0;
}