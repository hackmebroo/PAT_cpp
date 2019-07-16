#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
int n;
const int maxn = 100010;
LL sum[maxn];//sum[n]表示加到第n个钻石的价值
bool flag = false;//flag表示没有找到
int binarysearch(int A[], LL pay, int i){
    int right = n, left = i;
    while(left < right){
        int mid = (left + right) / 2;
        if(sum[mid] - sum[i] == pay){
            flag = false;
            return mid;
        } 
        else if(sum[mid] - sum[i] > pay) 
            right = mid;
        else if(sum[mid] - sum[i] < pay){
            left = mid + 1;
        }
    }
    if(left == right){
        if(sum[left] - sum[i] == pay){
            flag = false;
            return left;
        } 
    }
    flag = true;
    return left;
}
int main(){
    LL pay;
    scanf("%d %lld", &n, &pay);
    int input[n] = {};
    LL temp = 0;
    sum[0] = 0;
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &input[i]);
        sum[i] = temp;
        temp += input[i];
    }
    sum[n] = temp;
    int right;
    LL min = 1LL << 63 - 1;
    map<int, int>out1, out2;
    bool achieve = false;
    for(int i = 0; i < n; i++){
        right = binarysearch(input, pay, i);
        if(flag){
            temp = sum[right] - sum[i];
            if(temp < min && temp > pay){
                min = temp;
                out2.clear();
                out2[i + 1] = right;
                flag = false;
            }
            else if(temp == min && temp > pay){
                out2[i + 1] = right;
                flag = false;
            }    
        }
        else{
            out1[i +1] = right;
            achieve = true;
        }
    }
    if(achieve){
        map<int, int>::iterator it;
        for(it = out1.begin(); it != out1.end(); it++){
            printf("%d-%d\n", it -> first, it -> second);
        }
    }
    else{
        map<int, int>::iterator it;
        for(it = out2.begin(); it != out2.end(); it++){
            printf("%d-%d\n", it -> first, it -> second);
        }
    }
    return 0;
}