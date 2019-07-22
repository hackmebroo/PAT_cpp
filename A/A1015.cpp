#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int trans(int a, int radix){
    int result = 0;
    while(a != 0){
        result *= radix;
        int temp = a % radix;
        result += temp;
        a -= temp;
        a /= radix;
    }
    return result;
}
const int maxn = 100010;
int prime[maxn], pNum;
bool p[maxn] = {};
void findprime(){
    for(int i = 2; i < maxn; i++){
        if(!p[i]){
            prime[pNum++] = i;
            for(int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}
int main(){
    int temp1, temp2, trans_num;
    p[0] = true; p[1] = true;
    findprime();
    while(1){
        scanf("%d", &temp1);
        if(temp1 < 0)
            return 0;
        else {
            scanf("%d", &temp2);
            trans_num = trans(temp1, temp2);
            if(p[temp1] || p[trans_num])
                printf("No\n");
            else if(!p[temp1] && !p[trans_num])
                printf("Yes\n");
        }
    }
    return 0;
}