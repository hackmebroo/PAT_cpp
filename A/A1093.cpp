#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100010;
typedef long long LL;
char str[maxn];
int main(){
    scanf("%s", str);
    int len = strlen(str);
    LL num_P = 0 , sum = 0, AP_temp = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == 'P')
            num_P++;
        if(str[i] == 'A'){  
            AP_temp += num_P;
        }
        if(str[i] == 'T'){
            sum += AP_temp;
        }
    }
    printf("%lld", sum % 1000000007);
    return 0;
}   