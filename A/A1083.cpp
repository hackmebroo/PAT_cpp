#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct grade{
    char name[15];
    char id[15];
    int score;
}stu[100010], valid[100010];
bool cmp(grade a, grade b){
    return a.score > b.score;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
    int low, high;
    scanf("%d %d", &low, &high);
    sort(stu, stu + N, cmp);
    int count = 0;
    for(int i = 0; i < N; i++){
        if(stu[i].score >= low && stu[i].score <= high){
            valid[count] = stu[i];
            count++;
        }
    }
    if(count == 0)
        printf("NONE");
    else {
        // printf("%d\n", count);
        for(int i = 0; i < count; i++){
            printf("%s %s\n", valid[i].name, valid[i].id);
        }
    }
    return 0;
}