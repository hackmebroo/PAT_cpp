#include <cstring>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int inf = 0x3fffffff;
typedef long long LL;
int str[maxn] = {}, leftmax[maxn] = {}, rightmin[maxn] = {};
int ans[maxn], num = 0;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &str[i]);
    leftmax[0] = 0;
    for(int i = 1; i < n; i++)
        leftmax[i] = max(leftmax[i - 1], str[i - 1]);
    rightmin[n - 1] = inf;
    for(int i = n - 2; i >= 0; i--)
        rightmin[i] = min(rightmin[i + 1], str[i + 1]);
    for(int i = 0; i < n; i++){
        if(leftmax[i] < str[i] && rightmin[i] > str[i])
            ans[num++] = str[i];
    }
    printf("%d\n", num);
    for(int i = 0; i < num; i++){
        printf("%d", ans[i]);
        if(i < num - 1) printf(" ");
    }
    printf("\n");
    return 0;
}