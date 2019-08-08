#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 100010;

struct Node{
    int address;
    int key;
    int next;
    int flag;
}node[maxn];

bool cmp(Node a, Node b){
    if(a.flag == -1 || b.flag == -1)
        return a.flag > b.flag;
    else 
        return a.key < b.key;
}

void init(){
    for(int i = 0; i < maxn; i++)
        node[i].flag = -1;
}

int main(){
    init();
    int n, node1;
    scanf("%d %d", &n, &node1);
    for(int i = 0; i < n; i++){
        int address, key, next_address;
        scanf("%d %d %d", &address, &key, &next_address);
        node[address].address = address;
        node[address].key = key;
        node[address].next = next_address;
    }
    int p = node1, count = 0;
    while(p != -1){
        node[p].flag = 1;
        count++;
        p = node[p].next;
    }
    if(count == 0){
        printf("0 -1");
        return 0;
    }
    sort(node, node + maxn, cmp);
    printf("%d %05d\n", count, node[0].address);
    for(int i = 0; i < count; i++){
        if(i != count - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
        else 
            printf("%05d %d -1\n", node[i].address, node[i].key);
    }
    return 0;
}