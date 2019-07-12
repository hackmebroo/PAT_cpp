#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct station{
    double price;
    double begin;
    double end;
}gas[510], temp;
bool cmp(station a, station b){
    return a.begin < b.begin;
}
bool cmp1(double a, double b){
    return a < b;
}
int main(){
    int N;
    double full, dis, total;
    scanf("%lf %lf %lf %d", &full, &total, &dis, &N);
    double max_dis = full * dis;
    for(int i = 0; i < N; i++){
        scanf("%lf %lf", &gas[i].price, &gas[i].begin);
        gas[i].end = gas[i].begin + max_dis;
    }
    sort(gas, gas + N, cmp);
    if(gas[0].begin != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(i == N - 1){
            if(gas[i].end < total){
                printf("The maximum travel distance = %.2f", gas[i].end);
                return 0;
            }
        }
        else if(gas[i].end < gas[i + 1].begin && gas[i].end < total){
            printf("The maximum travel distance = %.2f", gas[i].end);
            return 0;
        }
    }
    double coordinate[2 * N];
    for(int i = 0; i < N; i++){
        coordinate[2 * i] = gas[i].begin;
        coordinate[2 * i + 1] = gas[i].end; 
    }
    sort(coordinate, coordinate + (2 * N), cmp1);

    double sum = 0.0;
    bool flag = false;
    for(int i = 0; i < 2 * N; i++){
        if(coordinate[i] == coordinate[i + 1])
            continue;
        if(coordinate[i + 1] >= total){
            coordinate[i + 1] = total;
            flag = true;
        }
        double min = 100000;
        for(int j = 0; j < N; j++){
            if(gas[j].begin > coordinate[i]){
                break;
            }
            if(gas[j].price < min && gas[j].end >= coordinate[i + 1] && gas[j].begin <= coordinate[i]){
                min = gas[j].price;
            }
        }
        sum += min * (coordinate[i + 1] - coordinate[i]);
        if(flag){
            printf("%.2f", sum / dis);
            return 0;
        }
    }
    return 0;

}