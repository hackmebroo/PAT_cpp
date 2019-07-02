#include <stdio.h>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int main(){
    char out[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char in[110] = {};
    cin.getline(in, 110);
    int i, j, len;
    long long sum = 0;
    len = strlen(in);
    for(i=0;i<len;i++){
        sum += (in[i] - '0');
    }
    int temp[100] = {};
    for(i=0;i<100;i++){
        if((sum / 10) != 0){
            temp[i] = sum % 10;
            sum /= 10;
        }
        else{
            temp[i] = sum;
            break;
        }
    }
    int k;
    for(j=0;j<=i;j++){
        k = 0;
        while(out[temp[i - j]][k] != 0){
            printf("%c", out[temp[i - j]][k]);
            k++;
        }
        if(j != i)
            printf(" ");
    }
    return 0;
}