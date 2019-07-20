#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int temp = 0, in, gap, sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &in);
        gap = in - temp;
        if(gap > 0)
            sum += (gap * 6 + 5);
        else 
            sum -= (gap * 4 - 5);
        temp = in;
    }
    printf("%d", sum);
    return 0;
}