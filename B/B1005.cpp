#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int hashtable[10010] = {};
void cal(int a){
    hashtable[a]++;
    if(a == 1)
        return ;
    if(a % 2 == 0){
        cal(a / 2);
        return ;
    }
    else{
        cal((3 * a + 1) / 2);
        return ;
    }
}
int main(){
    int N;
    scanf("%d", &N);
    int temp, in[110], p = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        cal(temp);
        in[p] = temp;
        p++;
    }
    sort(in, in + p);
    bool flag = true;
    for(int i = p - 1; i >= 0; i--){
        if(hashtable[in[i]] == 1){
            if(!flag)
                printf(" ");
            printf("%d", in[i]);
            flag = false;
        }
    }
    return 0;
}