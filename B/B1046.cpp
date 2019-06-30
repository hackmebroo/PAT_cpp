#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int num, i;
    scanf("%d",&num);
    int a[num][4];
    for(i=0;i<num;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    int flag1 = 0,flag2 = 0;
    for(i=0;i<num;i++){
        if(a[i][0] + a[i][2] == a[i][1] && a[i][0] + a[i][2] != a[i][3])
            flag2 += 1;
        else if(a[i][0] + a[i][2] != a[i][1] && a[i][0] + a[i][2] == a[i][3])
            flag1 += 1;
        else
            continue;
    }
    printf("%d %d",flag1,flag2);
    return 0;
}