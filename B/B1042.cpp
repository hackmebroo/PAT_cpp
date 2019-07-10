#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int hashtable[30] = {};
int main(){
    char str[1010];
    cin.getline(str, 1010);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            hashtable[str[i] - 'a']++;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            hashtable[str[i] - 'A']++;
    }
    int max = 0;
    for(int i = 0; i < 30; i++){
        if(hashtable[i] > max)
            max = hashtable[i];    
    }
    for(int i = 0; i < 30; i++){
        if(hashtable[i] == max){
            printf("%c ", 'a' + i);
            break;
        }
    }
    printf("%d", max);
    return 0;
}