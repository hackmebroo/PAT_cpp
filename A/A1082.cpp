#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
//这段代码垃圾的一批

int main(){
    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    int blank = 0;

    if(len == 1 && str[0] == '0'){
        printf("ling");
        return 0;
    }

    if(str[0] == '-'){
        printf("Fu");
        blank++;
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
    }
    int sign = 0, zero = 0;
    char change[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int W = 0;//万位
    if(len == 9 && str[1] == '0' && str[2] == '0' && str[3] == '0' && str[4] == '0')
        W = 1;
    if(len >= 9){
        if(blank != 0)
            printf(" ");
        printf("%s Yi", change[str[0] - '0']);
        blank++;
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 8){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0' && str[2] == '0' && str[3] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Qian", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 7){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0' && str[2] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Bai", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 6){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Shi", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 5){
        if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
        if(W == 0){
            if(blank != 0)
                printf(" ");
            printf("Wan");
            blank++;
        }
        else if(!(str[1] == '0' && str[2] == '0' && str[3] == '0' && str[4] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
        }
        zero = 0;
    }
    if(len >= 4){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0' && str[2] == '0' && str[3] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Qian", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 3){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0' && str[2] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Bai", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 2){
        if(sign != 0 && str[0] == '0' && zero == 0 && !(str[1] == '0')){
            if(blank != 0)
                printf(" ");
            printf("ling");
            blank++;
            zero++;
        }
        else if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s Shi", change[str[0] - '0']);
            blank++;
            if(zero != 0)
                zero--;
        }
        for(int i = 0; i < len - 1; i++)
            str[i] = str[i + 1];
        len--;
        sign++;
    }
    if(len >= 1){
        if(str[0] != '0'){
            if(blank != 0)
                printf(" ");
            printf("%s", change[str[0] - '0']);
        }
    }
    return 0;
}