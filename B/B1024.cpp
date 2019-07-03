#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    int j, len, p = 0;
    char sign1, sign2, str[10010], real[10000], fraction[10000], exponent[10000];
    scanf("%c%s", &sign1, &str);
    len = strlen(str);
    for(j=0;j<len;j++){
        if(str[j] != '.'){
            real[p] = str[j];
            p++;
        }
        else 
            break;
    }
    int i, len1, len2, len3;
    len1 = strlen(real);
    p = 0;
    for(j=len1+1;j<len;j++){
        if(str[j] != 'E'){
            fraction[p] = str[j];
            p++;
        }
        else 
            break;
    }
    len2 = strlen(fraction);
    sign2 = str[len1 + len2 + 2];
    p = 0;
    for(j=len1+len2+3;j<len;j++){
        exponent[p] = str[j];
        p++;
    }
    len3 = strlen(exponent);

    if(sign1 == '-')
        printf("-");

    //计算exponent的值
    int count = 0, sum = 0;
    for(i=0;i<len3;i++){
        if(exponent[i] == '0' && count == 0)
            continue;
        else{
            if(count == 0)
                sum += exponent[i] - '0';
            else{
                sum *= 10;
                sum += exponent[i] - '0';
            }
            count ++;
        }
    } 

    if(sign2 == '+'){
        if(sum >= len2){
            for(i=0;i<len1;i++)
                printf("%c", real[i]);
            for(i=0;i<len2;i++)
                printf("%c", fraction[i]);
            for(i=0;i<sum-len2;i++)
                printf("0");
        }
        else {
            for(i=0;i<len1;i++)
                printf("%c", real[i]);
            for(i=0;i<=len2 - sum;i++)
                printf("%c", fraction[i]);
            printf(".");
            for(i=len2 - sum + 1;i<len2;i++)
                printf("%c", fraction[i]);
        }
    }

    else if(sign2 == '-'){
        printf("0.");
        for(i=0;i<sum-len1;i++)
            printf("0");
        for(i=0;i<len1;i++)
            printf("%c", real[i]);        
        for(i=0;i<len2;i++)
            printf("%c", fraction[i]);
        
    }
    return 0;
}