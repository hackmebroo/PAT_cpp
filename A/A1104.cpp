#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double temp, sum = 0.0;
    for(int i = 0; i < n; i++){
        scanf("%lf", &temp);
        sum += temp * (i + 1) * (n - i);
    }
    printf("%.2lf", sum);
    return 0;
}