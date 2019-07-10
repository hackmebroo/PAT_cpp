#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100010;
bool hashtable[256];
char str[maxn];
int main(){
    memset(hashtable, true, sizeof(hashtable));
    cin.getline(str, maxn);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
        hashtable[str[i]] = false;
    }

    int count = 0;
    for(int i = 0; i < 256; i++){
        if((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9') || i == '-' || i == '+' || i == ',' || i == '.' || i == '_')
            if(hashtable[i])
                count++;
    }
    if(count == 0){
        printf("\n");
        return 0;
    }

    if(strlen(str) == 0){
        scanf("%s", str);
        printf("%s", str);
        return 0;
    }
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            int low = str[i] - 'A' + 'a';
            if(hashtable[low] == true && hashtable['+'] == true)
                printf("%c", str[i]);
        }
        else if(hashtable[str[i]] == true)
            printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}