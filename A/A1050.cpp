#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
bool hashatble[129] = {false};
int main(){
    char str1[10010], str2[10010];
    cin.getline(str1, 10010);
    cin.getline(str2, 10010);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0; i < len2; i++){
        if(!hashatble[str2[i]])
            hashatble[str2[i]] = true;
    }
    for(int i = 0; i < len1; i++){
        if(!hashatble[str1[i]])
            printf("%c", str1[i]);
    }
    return 0;
}
