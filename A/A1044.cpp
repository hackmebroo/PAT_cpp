#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
// int n;
// const int maxn = 100010;
// LL sum[maxn];//sum[n]表示加到第n个钻石的价值
// bool flag = false;//flag表示没有找到
// int binarysearch(int A[], LL pay, int i){
//     int right = n, left = i;
//     while(left < right){
//         int mid = (left + right) / 2;
//         if(sum[mid] - sum[i] == pay){
//             flag = false;
//             return mid;
//         } 
//         else if(sum[mid] - sum[i] > pay) 
//             right = mid;
//         else if(sum[mid] - sum[i] < pay){
//             left = mid + 1;
//         }
//     }
//     if(left == right){
//         if(sum[left] - sum[i] == pay){
//             flag = false;
//             return left;
//         } 
//     }
//     flag = true;
//     return left;
// }
// int main(){
//     LL pay;
//     scanf("%d %lld", &n, &pay);
//     int input[n] = {};
//     LL temp = 0;
//     sum[0] = 0;
//     int i;
//     for(i = 0; i < n; i++){
//         scanf("%d", &input[i]);
//         sum[i] = temp;
//         temp += input[i];
//     }
//     sum[n] = temp;
//     int right;
//     LL min = 1LL << 63 - 1;
//     map<int, int>out1, out2;
//     bool achieve = false;
//     for(int i = 0; i < n; i++){
//         right = binarysearch(input, pay, i);
//         if(flag){
//             temp = sum[right] - sum[i];
//             if(temp < min && temp > pay){
//                 min = temp;
//                 out2.clear();
//                 out2[i + 1] = right;
//                 flag = false;
//             }
//             else if(temp == min && temp > pay){
//                 out2[i + 1] = right;
//                 flag = false;
//             }    
//         }
//         else{
//             out1[i +1] = right;
//             achieve = true;
//         }
//     }
//     if(achieve){
//         map<int, int>::iterator it;
//         for(it = out1.begin(); it != out1.end(); it++){
//             printf("%d-%d\n", it -> first, it -> second);
//         }
//     }
//     else{
//         map<int, int>::iterator it;
//         for(it = out2.begin(); it != out2.end(); it++){
//             printf("%d-%d\n", it -> first, it -> second);
//         }
//     }
//     return 0;
// }


const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

int upper_bound(int L, int R, int x){
    int left = L, right = R, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(sum[mid] > x)
            right = mid;
        else 
            left = mid + 1;
    }
    return left;
}

int main(){
    scanf("%d%d", &n, &S);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i <= n; i++){
        int j = upper_bound(i, n + 1, sum[i - 1] + S);
        if(sum[j - 1] - sum[i - 1] == S){
            nearS = S;
            break;
        }
        else if(j <= n && sum[j] - sum[i - 1] < nearS)
            nearS = sum[j] - sum[i - 1];
    }
    for(int i = 1; i <= n; i++){
        int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
        if(sum[j - 1] - sum[i - 1] == nearS)
            printf("%d-%d\n", i, j - 1);
    }
    return 0;
}