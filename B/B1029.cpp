#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool hashtable[65] = {};//0-9对应数字0-9, 10-35对应a-z，36-61对应A-Z，62对应_
void init(){
    for(int i = 0; i < 65; i++)
        hashtable[i] = true;
}
int trans(char a){
    if(a - '0' <= 9 && a - '0' >= 0) return a - '0';
    else if (a - 'a' <= 25 && a - 'a' >= 0) return a - 'a' + 10;
    else if (a - 'A' <= 25 && a - 'A' >= 0) return a - 'A' + 36;
    else if (a == '_') return 62;
}
char retrans(int a){
    if(a >= 0 && a <= 9) return '0' + a;
    else if(a >= 10 && a <= 35) return 'A' + a - 10;
    else if(a >= 36 && a <= 61) return 'A' + a - 36;
    else return '_';
}
int main(){
    init();
    char origin[100], input[100];
    scanf("%s %s", origin, input);
    for(int i = 0; i < strlen(origin); i++)
        hashtable[trans(origin[i])] = false;
    for(int i = 0; i < strlen(input); i++)
        hashtable[trans(input[i])] = true;
    for(int i = 0; i < strlen(origin) ; i++){
        if(!hashtable[trans(origin[i])]){
            char temp = retrans(trans(origin[i]));
            printf("%c", temp);
            if(trans(origin[i]) >= 10 && trans(origin[i]) <= 35){
                hashtable[trans(origin[i])] = true;
                hashtable[trans(origin[i]) + 26] = true;
            }
            else if(trans(origin[i]) >= 36 && trans(origin[i]) <= 61){
                hashtable[trans(origin[i])] = true;
                hashtable[trans(origin[i]) - 26] = true;
            }
            else 
                hashtable[trans(origin[i])] = true;
        }
    }
    return 0;
}