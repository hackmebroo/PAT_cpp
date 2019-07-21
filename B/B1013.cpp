#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000010;
int prime[maxn], pNum = 0;
bool p[maxn] = {};
void findprime(){
    for(int i = 2; i < maxn; i++){
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}
int main(){
    int low, high;
    scanf("%d %d", &low, &high);
    findprime();
    int count = 0, pri = 0;
    for(int i = 2; i < maxn; i++){
        if(!p[i]){
            count++;
            if(count >= low && count <= high){
                if(pri % 10 != 0)
                    printf(" ");
                pri++;
                printf("%d", i);
                if(pri % 10 == 0)
                    printf("\n");
            }
        }
        if(count >= high)
            return 0;
    }
    return 0;
}