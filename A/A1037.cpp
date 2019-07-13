#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int N;
    scanf("%d", &N);
    int coupon[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &coupon[i]);
    int M;
    scanf("%d", &M);
    int product[M];
    for(int i = 0; i < M; i++)
        scanf("%d", &product[i]);
    sort(coupon, coupon + N, cmp);
    sort(product, product + M, cmp);
    int sum = 0;
    for(int i = 0; i < N && i < M; i++){
        if(coupon[i] > 0 && product[i] > 0){
            sum += coupon[i] * product[i];
        }
        else 
            break;
    } 
    int i = N - 1, j = M - 1;
    while(i >= 0 && j >= 0 && coupon[i] < 0 && product[j] < 0){
        sum += coupon[i] * product[j];
        i--;
        j--;
    }
    printf("%d", sum);
    return 0;
}