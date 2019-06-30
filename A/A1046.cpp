#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, N, cal, sum = 0, sum1 = 0;
    scanf("%d",&N);
    int road[N], dist[N];
    for(i=0;i<N;i++){
        scanf("%d",&road[i]);
        if(i == 0)
            dist[i] = 0;
        else
            dist[i] = sum;
        sum += road[i];     //闭环总长度
    }
    sum1 = sum / 2;
    scanf("%d",&cal);
    int j, temp, temp1, temp2;
    for(i=0;i<cal;i++){
        int all = 0;
        scanf("%d%d",&temp1, &temp2);
        if(temp1 < temp2){
            all = dist[temp2 - 1] - dist[temp1 -1];
        }
        else{
            all = dist[temp1 - 1] - dist[temp2 -1];
        }
        if(all <= sum1)
            printf("%d", all);
        else
            printf("%d", sum - all);
        if(i != cal - 1)
            printf("\n");
        else
            continue;
    }
    return 0;
}