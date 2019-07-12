#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct mooncake{
    double amount;
    double price;
    double price_per;
}cake[1010];
bool cmp(mooncake a, mooncake b){
    return a.price_per > b.price_per;
}
int main(){
    int N;
    double most;
    scanf("%d %lf", &N, &most);
    for(int i = 0; i < N; i++)
        scanf("%lf", &cake[i].amount);
    for(int i = 0; i < N; i++){
        scanf("%lf", &cake[i].price);
        cake[i].price_per = cake[i].price / cake[i].amount;
    }
    sort(cake, cake + N, cmp);
    int i = 0;
    double sum = 0.0;
    while(most > 0 && i < N){
        if(cake[i].amount <= most){
            sum += cake[i].price;
            most -= cake[i].amount;
            i++;
        }
        else{
            sum += most * cake[i].price_per;
            printf("%.2f", sum);
            return 0;
        }
    }
    printf("%.2f", sum);
    return 0;
}