#include <iostream>
#include <cstring>
#include <cstdio>
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
    int high;
    scanf("%d", &high);
    findprime();
    int temp = prime[0], count = 0;
    for(int i = 1; prime[i] <= high; i++){
        int temp_now = prime[i];
        if(temp_now - temp == 2)
            count++;
        temp = temp_now;
    }
    printf("%d", count);
    return 0;
}