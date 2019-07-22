#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int main(){
    LL a;
    scanf("%lld", &a);
    int sqr = (int)sqrt(1.0 * a);
    int temp, max_len = 0, chosen, max = 0;
    for(int i = 2; i <= sqr; i++){
        max_len = 0;
        temp = a;
        int j = i;
        while(temp % j == 0 && temp >= j){
            max_len++;
            temp /= j;
            j++;
        }
        if(max_len > max){
            max = max_len;
            chosen = i;
        }
    }
    if(max == 0){
        printf("1\n");
        printf("%d", a);
        return 0;
    }
    if(max == 1){
        printf("1\n");
        printf("%d", chosen);
    }
    else{
        printf("%d\n", max);
        for(int i = 0; i < max; i++){
            printf("%d", chosen++);
            if(i != max - 1)
                printf("*");
        }
    }
    return 0;
}