#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
// bool hashtable[100010] = {false};
// int in[100010] = {};
// int index[100010] = {};
// bool flag[100010] = {false};
int main(){
    bool hashtable[100010] = {false};
    int in[100010] = {};
    int index[100010] = {};
    bool flag[100010] = {false};
    int N, temp, p = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        if(!hashtable[temp]){
            hashtable[temp] = true;
            in[p] = temp;
            index[temp] = p;
            p++;
        }
        else{
            flag[index[temp]] = true;
        }
    }
    for(int i = 0; i < p; i++){
        if(!flag[i]){
            printf("%d", in[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}