#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
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
struct factor{
    int x, cnt;
}fac[20];
int facNum;
void findfactor(int a){
    int sqr = sqrt(1.0 * a);
    facNum = 0;
    for(int i = 0; i <= sqr && a > prime[i]; i++){
        if(a % prime[i] == 0){
            fac[facNum].x = prime[i];
            fac[facNum].cnt = 0;
            while(a % prime[i] == 0){
                fac[facNum].cnt++;
                a /= prime[i];
            }
            facNum++;
        }
    }
    if(a != 1){
        fac[facNum].x = a;
        fac[facNum++].cnt = 1;
    }
    return;
}
int main(){
    int a;
    scanf("%d", &a);
    if(a == 1){
        printf("1=1");
        return 0;
    }
    findprime();
    findfactor(a);
    printf("%d=", a);
    for(int i = 0; i < facNum; i++){
        printf("%d", fac[i].x);
        if(fac[i].cnt > 1)
            printf("^%d", fac[i].cnt);
        if(i != facNum - 1)
            printf("*");
    }
    return 0;
}