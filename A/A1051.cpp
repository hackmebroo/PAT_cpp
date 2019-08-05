#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int temp[N], stack[M];
    string str;
    for(int i = 0; i < K; i++){
        int top = -1, current = 1, last = 0;
        bool first = false;
        for(int j = 0; j < N; j++){
            scanf("%d", &temp[j]);
            if(temp[j] >= current){
                if(first)
                    last = current;
                current = temp[j];
                for(int k = last + 1; k <= current; k++){
                    stack[++top] = k;
                }//入栈
                first = true;
            }
            if(top > M - 1){
                printf("NO\n");
                getline(cin, str);
                break;
            }
            if(stack[top--] == temp[j]){
                if(j == N - 1)
                    printf("YES\n");
                else 
                    continue;
            }
            else{
                printf("NO\n");
                getline(cin, str);
                break;
            }
        }
    }
    return 0;
}