#include <stdio.h>
#include <iostream>
using namespace std;


int cal(int x){
    if(x % 2 == 0)//偶数
        return x / 2;
    else//奇数
        return (3 * x + 1) / 2;
}

int main(){
    int temp,count=0;
    cin >> temp;
    while(temp != 1){
        count++;
         temp = cal(temp);
    }
    printf("%d",count);
    return 0;
}