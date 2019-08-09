#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 100010;
struct Node{
    int address, key, next_address;
}node[maxn], result[maxn];

int main(){
    int begin, n, k, address, key, next_address;
    scanf("%d %d %d", &begin, &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &address, &key, &next_address);
        node[address].address = address;
        node[address].key = key;
        node[address].next_address = next_address;
    }
    int valid = 0, pos = begin;
    while(pos != -1){
        pos = node[pos].next_address;
        valid++;
    }
    int group = valid / k, p, p_result = 0, begin_temp = begin, group_temp;
    bool flag = false;
    for(int i = 0; i < group; i++){
        int count = 0;
        while(count < k){
            p = begin_temp;
            if(k == 1)
                group_temp = node[p].next_address;
            for(int j = 1; j < k - count; j++){
                p = node[p].next_address;
                if(j == k - 1)
                    group_temp = node[p].next_address;
            }
            result[p_result].address = node[p].address;
            result[p_result++].key = node[p].key;
            if(flag)
                result[p_result - 2].next_address = result[p_result - 1].address;
            flag = true;
            count++; 
        }
        begin_temp = group_temp;
    }
    int temp = k * group;
    if(valid % k != 0){
        p = begin;
        while(--temp){
            p = node[p].next_address;
        }
        result[p_result - 1].next_address = node[p].next_address;
        p = node[p].next_address;
        while(p != -1){
            result[p_result].address = node[p].address;
            result[p_result].key = node[p].key;
            result[p_result++].next_address = node[p].next_address;
            p = node[p].next_address;
        }
    }
    else{
        result[p_result - 1].next_address = -1;
    }
    for(int i = 0; i < p_result; i++){
        if(i != p_result - 1)
            printf("%05d %d %05d\n", result[i].address, result[i].key, result[i].next_address);
        else 
            printf("%05d %d -1\n", result[i].address, result[i].key);
    }
    return 0;
}