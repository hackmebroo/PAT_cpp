#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    double bet[3][3];
    int i, j;
    for(i=0;i<3;i++)
        cin >> bet[i][0] >> bet[i][1] >> bet[i][2];
    double max[3] = {};
    int max_index[3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(bet[i][j] > max[i]){
                max[i] = bet[i][j];
                max_index[i] = j;
            }
        }
        if(max_index[i] == 0)
            printf("W ");
        else if(max_index[i] == 1)
            printf("T ");
        else 
            printf("L ");
    }
    double temp;
    temp = (max[0] * max[1] * max[2] * 0.65 - 1) * 2;
    printf("%.2f", temp);
    return 0;
}