#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int N, i;
    cin >> N;
    int score[N] = {};
    int temp1, temp2;
    for(i=0;i<N;i++){
        cin >> temp1 >> temp2;
        score[temp1 - 1] += temp2;
    }
    int max = 0, max_index = 0;
    for(i=0;i<N;i++){
        if(score[i] > max){
            max = score[i];
            max_index = i + 1;
        }
    }
    printf("%d %d",max_index,max);
    return 0;
}