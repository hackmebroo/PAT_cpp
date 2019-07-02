#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    int i, j, sum = 0, count = 0, weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char M[11] = {'1', '0', 'X', '9', '8', '7', '6' , '5', '4', '3', '2'}, temp[20] = {};
    for(i=0;i<N;i++){
        sum = 0;
        scanf("%s", temp);
        for(j=0;j<17;j++){
            sum += weight[j] * (temp[j] - '0');
        }
        sum %= 11;
        if(temp[17] == M[sum])
            continue;
        else{
            count++;
            for(j=0;j<18;j++)
                printf("%c",temp[j]);
        }
        printf("\n");
    }
    if(count == 0)
        printf("All passed");
    return 0;
}