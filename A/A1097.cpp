#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100010;
const int max_abs = 10010;
bool hashtable[max_abs] = {};
struct Node{
    int address, key, next_address;
}node[maxn], chosen_list[maxn], removed_list[maxn];

int main(){
    int begin, n;
    scanf("%d %d", &begin, &n);
    int address, key, next_address, count = 0, p, last_address;
    bool flag = false;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &address, &key, &next_address);
        node[address].address = address;
        node[address].key = key;
        node[address].next_address = next_address;
    }
    p = begin;
    int p1 = 0;
    while(p != -1){
        if(!hashtable[abs(node[p].key)]){
            chosen_list[p].address = p;
            chosen_list[p].key = node[p].key;
            if(flag)
                chosen_list[last_address].next_address = p;
            last_address = p;
            flag = true;
            hashtable[abs(node[p].key)] = true;
            count++;
        }
        else{
            removed_list[p1].address = p;
            removed_list[p1++].key = node[p].key;
            if(p1 > 1)
                removed_list[p1 - 2].next_address = p;
        }  
        p = node[p].next_address;
    }
    chosen_list[last_address].next_address = -1;
    p = begin;
    while(p != -1){
        if(count != 1)
            printf("%05d %d %05d\n", chosen_list[p].address, chosen_list[p].key, chosen_list[p].next_address);
        else 
            printf("%05d %d -1\n", chosen_list[p].address, chosen_list[p].key);
        count--;
        p = chosen_list[p].next_address;
    }
    for(int i = 0; i < p1; i++){
        if(i != p1 - 1)
            printf("%05d %d %05d\n", removed_list[i].address, removed_list[i].key, removed_list[i].next_address);
        else 
            printf("%05d %d -1\n", removed_list[i].address, removed_list[i].key);
    }
    return 0;
}