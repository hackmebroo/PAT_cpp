#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    char str[N][1010], team[N][1010];
    for(int i = 0; i < N ; i++){
        scanf("%s %s", team[i] ,str[i]);
    }
    int sign = 0, count = 0, out[N] = {}, p = 0;
    for(int i = 0; i < N; i++){
        sign = 0;
        for(int j = 0; j < 1010; j++){
            if(str[i][j] == 0)
                break;
            else{
                if(str[i][j] == '1'){
                    str[i][j] = '@';
                    sign++;
                }
                else if(str[i][j] == '0'){
                    str[i][j] = '%';
                    sign++;
                }
                else if(str[i][j] == 'l'){
                    str[i][j] = 'L';
                    sign++;
                }
                else if(str[i][j] == 'O'){
                    str[i][j] = 'o';
                    sign++;
                }
            }
        }
        if(sign != 0){
            count++;
            out[p] = i;
            p++;
        }
    }
    if(N == 1 && count == 0)
        printf("There is %d account and no account is modified", N);
    else if(N != 1 && count == 0)
        printf("There are %d accounts and no account is modified", N);
    else {
        printf("%d\n", count);
        for(int i = 0; i < p; i++){
            printf("%s %s", team[out[i]], str[out[i]]);
            if(i != p - 1)
                printf("\n");
        }
    }
    return 0;
}