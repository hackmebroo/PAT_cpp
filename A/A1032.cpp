#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 100010;
struct Node{
    char data;
    int next;
    bool flag;
}node[maxn];

int main(){
    int node1, node2, n;
    scanf("%d %d %d", &node1, &node2, &n);
    for(int i = 0; i < n; i++){
        int address, next_address;
        char data_temp;
        scanf("%d %c %d", &address, &data_temp, &next_address);
        node[address].data = data_temp;
        node[address].next = next_address;
    }
    int p;
    for(p = node1; p != -1; p = node[p].next){
        node[p].flag = true;
    }
    for(p = node2; p != -1; p = node[p].next){
        if(node[p].flag){
            printf("%05d", p);
            return 0;
        }
    }
    printf("-1");
    return 0;
}