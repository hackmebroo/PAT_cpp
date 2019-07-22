#include <iostream>
#include <cstdio>
#include <cstring>
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
int main(){
    int Msize, n, temp, a;
    scanf("%d%d", &Msize, &n);
    findprime();
    p[0] = true; p[1] = true;
    if(p[Msize]){
        for(int i = Msize + 1; i < maxn; i++){
            if(!p[i]){
                Msize = i;
                break;
            }
        }
    }
    bool judge[Msize] = {};
    for(int i = 0; i < n; i++){
        bool flag = false;
        scanf("%d", &a);
        temp = a % Msize;
        if(!judge[temp]){
            printf("%d", temp);
            judge[temp] = true;
        }
        else{
            for(int i = 1; i < Msize; i++){
                temp = (a + (i * i)) % Msize;
                if(!judge[temp] && temp < Msize){
                    printf("%d", temp);
                    judge[temp] = true;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                printf("-");
        }
        if(i != n - 1)
            printf(" ");
    }
    return 0;
}