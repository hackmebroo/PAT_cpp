#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 1010;
struct mice{
    int rank, weight;
}mouse[maxn];


int main(){
    int Np, Ng;
    scanf("%d %d", &Np, &Ng);
    for(int i = 0; i < Np; i++){
        scanf("%d", &mouse[i].weight);
    }
    queue<int>q;
    int order;
    for(int i = 0; i < Np; i++){
        scanf("%d", &order);
        q.push(order);
    }
    int temp = Np, group;
    while(q.size() != 1){
        if(temp % Ng == 0)
            group = temp / Ng;
        else 
            group = temp / Ng + 1;
        for(int i = 0; i < group; i++){
            int k = q.front();
            for(int j = 0; j < Ng; j++){
                if(i * Ng + j >= temp) break;
                int front = q.front();
                if(mouse[front].weight > mouse[k].weight)
                    k = front;
                mouse[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].rank = 1;
    for(int i = 0; i < Np; i++){
        printf("%d", mouse[i].rank);
        if(i != Np - 1) printf(" ");
    }
    return 0;
}