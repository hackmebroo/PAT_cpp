#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, N;
    cin >> N;
    int in[N];
    for(i=0;i<N;i++)
        cin >> in[i];
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0.0;
    int flag = 0, sign = 0, count = 0, max = 0;
    for(i=0;i<N;i++){
        if(in[i] % 10 == 0)
            A1 += in[i];
        else if(in[i] % 5 == 1){
            flag++;
            if(sign % 2 == 0)
                A2 += in[i];
            else
                A2 -= in[i];
            sign++;
        }
        else if(in[i] % 5 == 2)
            A3++;
        else if(in[i] % 5 == 3){
            A4 += in[i];
            count++;
        }
        else if(in[i] % 5 == 4){
            if(in[i] > max)
                max = in[i];
        }
    }
    if(A1 == 0)
        printf("N ");
    else
        printf("%d ",A1);
    if(flag == 0)
        printf("N ");
    else
        printf("%d ", A2);
    if(A3 == 0)
        printf("N ");
    else
        printf("%d ",A3);
    if(A4 == 0)
        printf("N ");
    else
        printf("%.1f ",A4 / count);
    if(max == 0)
        printf("N");
    else
        printf("%d",max);
}