#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int cal(int a[], int b[]){
    int tempa = 0, tempb = 0;
    for(int i = 0; i < 4; i++){
        tempa *= 10;
        tempb *= 10;
        tempa += a[i];
        tempb += b[i];
    }
    return tempa - tempb;
}
int main(){
    int num[4] = {}, num1[4] = {}, in;
    scanf("%d", &in);
    num[0] = in / 1000;
    num[1] = (in % 1000) / 100;
    num[2] = (in % 100) / 10;
    num[3] = in % 10;
    if(num[0] == num[1] && num[0] == num[2] && num[0] == num[3]){
        printf("%d%d%d%d - %d%d%d%d = 0000", num[0], num[1], num[2], num[3], num[0], num[1], num[2], num[3]);
        return 0;
    }
    sort(num, num + 4, cmp);
    for(int i = 0; i < 4; i++)
        num1[i] = num[i];
    int result = 0;
    while(result != 6174){
        swap(num1[0], num1[3]);
        swap(num1[1], num1[2]);
        result = cal(num, num1);
        printf("%d%d%d%d - %d%d%d%d = %d%d%d%d\n", num[0], num[1], num[2], num[3], num1[0], num1[1], num1[2], num1[3], result / 1000, (result % 1000) / 100, (result % 100) / 10, result % 10);
        num1[0] = result / 1000;
        num1[1] = (result % 1000) / 100;
        num1[2] = (result % 100) / 10;
        num1[3] = result % 10;
        sort(num1, num1 + 4, cmp);
        for(int i = 0; i < 4; i++)
            num[i] = num1[i];
    }
    return 0;
}