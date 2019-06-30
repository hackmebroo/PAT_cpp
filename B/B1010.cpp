#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i = 0, temp1, temp2;
    while(scanf("%d%d",&temp1, &temp2) != EOF){
        if(i == 0){
            if(temp2 == 0){
                printf("0 0");
                break;
            }
            else
                printf("%d %d", temp1 * temp2, temp2 - 1);
        }
        else{
            if(temp2 != 0)
                printf(" %d %d", temp1 * temp2, temp2 - 1);
            else
                break;
        }
        i++;
    }
    return 0;
}