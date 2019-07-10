#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int hashtable[256] = {};
int main(){
    char str[1010];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        hashtable[str[i]]++;
    }
    scanf("%s", str);
    len = strlen(str);
    for(int i = 0; i < len; i++){
        hashtable[str[i]]--;
    }
    int count1 = 0, count2 = 0;
    for(int i = 0; i < 256; i++){
        if(hashtable[i] > 0)
            count1 += hashtable[i];
        if(hashtable[i] < 0)
            count2 -= hashtable[i];
    }
    if(count2 > 0)
        printf("No %d", count2);
    else 
        printf("Yes %d", count1);
    return 0;
}