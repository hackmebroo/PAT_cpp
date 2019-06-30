#include <iostream>
#include <stdio.h>
using namespace std;
struct student{
    char name[15];
    char id[15];
    int score;
}temp, in_max, in_min;

int main(){
    int i, N;
    cin >> N;
    in_max.score = -1;
    in_min.score = 101;
    for(i=0;i<N;i++){
        scanf("%s%s%d", temp.name, temp.id, &temp.score);
        if(temp.score > in_max.score)
            in_max = temp;
        if(temp.score < in_min.score)
            in_min = temp;
    }
    printf("%s %s\n",in_max.name, in_max.id);
    printf("%s %s",in_min.name, in_min.id);
    return 0;
}