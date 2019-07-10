#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int hashtable[128] = {};
int main(){
    char str[10010];
    scanf("%s", str);
    int len = strlen(str);
    int P = 0, A = 0, T = 0, t = 0, e = 0, s = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == 'P')
            P++;
        else if(str[i] == 'A')
            A++;
        else if(str[i] == 'T')
            T++;
        else if(str[i] == 't')
            t++;
        else if(str[i] == 'e')
            e++;
        else if(str[i] == 's')
            s++;
    }
    while(P != 0 || A != 0 || T != 0 || t != 0 || e != 0 || s != 0){
        if(P != 0){
            printf("P");
            P--;
        }
        if(A != 0){
            printf("A");
            A--;
        }
        if(T != 0){
            printf("T");
            T--;
        }
        if(e != 0){
            printf("e");
            e--;
        }
        if(s != 0){
            printf("s");
            s--;
        }
        if(t != 0){
            printf("t");
            t--;
        }
    }
    return 0;
}