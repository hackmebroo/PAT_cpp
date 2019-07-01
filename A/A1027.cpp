#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int i, j, n[3];
    cin >> n[0] >> n[1] >> n[2];
    char num[3][2];
    int temp1, temp2;
    printf("#");
    for(i=0;i<3;i++){
        num[i][0] = n[i] / 13;
        num[i][1] = n[i] % 13;
        for(j=0;j<2;j++){
            if(num[i][j] >= 10){
                if(num[i][j] == 10){
                    num[i][j] = 'A';
                    printf("%c",num[i][j]);
                }
                else if(num[i][j] ==11){
                    num[i][j] = 'B';
                    printf("%c",num[i][j]);
                }
                else{
                    num[i][j] = 'C';
                    printf("%c",num[i][j]);
                }
            }
            else 
                printf("%d",num[i][j]);
        }
    }
    // printf("#%d%c%c%c%c%c", num[0][0], num[0][1], num[1][0], num[1][1], num[2][0], num[2][1]);
    return 0;
}