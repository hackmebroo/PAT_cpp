#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    char s1[70], s2[70] ,s3[70] ,s4[70];
    char week[7][5] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i, j, len1, len2, len3, len4;
    scanf("%s", &s1); scanf("%s", &s2); scanf("%s", &s3); scanf("%s", &s4);
    len1 = strlen(s1); len2 = strlen(s2); len3 = strlen(s3); len4 = strlen(s4);
    int temp;
    for(i=0;i<len1 && i<len2;i++){
        if((s1[i] == s2[i]) && (s1[i] >= 'A' && s1[i] <= 'G')){
            printf("%s ", week[s1[i] - 'A']);
            break;
        }
    }
    for(j=i+1;j<len1 && j<len2;j++){
        if((s1[j] == s2[j]) && (s1[j] >= 'A' && s1[j] <= 'N')){  
            printf("%02d:", s1[j] - 'A' + 10);
            break;
        }
        else if((s1[j] == s2[j]) && (s1[j] >= '0' && s1[j] <= '9')){
            printf("%02d:", s1[j] - '0');
            break;
        }
    }
    int count = 0;
    for(i=0;i<len3 && i<len4;i++){
        if((s3[i] == s4[i]) && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))){
            printf("%02d", count);
            break;
        }
        else 
            count++;
    }
    return 0;
}