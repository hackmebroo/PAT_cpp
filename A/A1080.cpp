#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, K;
struct student{
    int id;
    int G_E;
    int G_I;
    int choices[6];
    int average;
}stu[40010];
struct school{
    int max;
    bool full;
    int student[40010];
    int average[40010];
    int G_E[40010];
    int num;
}sch[110];
void init(){
    for(int i = 0; i < K; i++){
        if(sch[i].max != 0)
            sch[i].full = false;
        else 
            sch[i].full = true;
        sch[i].num = 0;
    }
    for(int i = 0; i < N; i++){
        stu[i].id = i;
    }
}
bool cmp(student a, student b){
    if(a.average != b.average) return a.average > b.average;
    else return a.G_E > b.G_E;
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++)
        scanf("%d", &sch[i].max);
    init();
    for(int i = 0; i < N; i++){
        scanf("%d %d", &stu[i].G_E, &stu[i].G_I);
        stu[i].average = (stu[i].G_E + stu[i].G_I);
        for(int j = 0; j < K; j++)
            scanf("%d", &stu[i].choices[j]);
    }
    sort(stu, stu + N, cmp);
    // printf("%d %d", stu[0].id, stu[1].id);
    // sort(stu, stu + N, cmp);
    // printf("%d %d", stu[0].id, stu[1].id);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            if(!sch[stu[i].choices[j]].full && sch[stu[i].choices[j]].num <= sch[stu[i].choices[j]].max - 1){//学校没招满,且不会出现超员情况
                sch[stu[i].choices[j]].student[sch[stu[i].choices[j]].num] = stu[i].id;
                sch[stu[i].choices[j]].average[sch[stu[i].choices[j]].num] = stu[i].average;
                sch[stu[i].choices[j]].G_E[sch[stu[i].choices[j]].num] = stu[i].G_E;
                sch[stu[i].choices[j]].num++;
                break;
            }
            else if(!sch[stu[i].choices[j]].full && sch[stu[i].choices[j]].num >= sch[stu[i].choices[j]].max){
                if(stu[i].average ==  sch[stu[i].choices[j]].average[sch[stu[i].choices[j]].num - 1] && stu[i].G_E ==  sch[stu[i].choices[j]].G_E[sch[stu[i].choices[j]].num - 1]){
                    // printf("%d %d", stu[i].G_E, sch[stu[i].choices[j]].student[sch[stu[i].choices[j]].num - 1]);
                    sch[stu[i].choices[j]].student[sch[stu[i].choices[j]].num] = stu[i].id;
                    sch[stu[i].choices[j]].average[sch[stu[i].choices[j]].num] = stu[i].average;
                    sch[stu[i].choices[j]].G_E[sch[stu[i].choices[j]].num] = stu[i].G_E;
                    sch[stu[i].choices[j]].num++;
                    // printf("%d %d", stu[i].G_E, stu[sch[stu[i].choices[j]].student[sch[stu[i].choices[j]].num - 1]].G_E);
                    break;
                }
                else 
                    sch[stu[i].choices[j]].full = true;
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(sch[i].num == 0)
            printf("\n");
        else{
            sort(sch[i].student, sch[i].student + sch[i].num);
            for(int j = 0; j < sch[i].num; j++){
                printf("%d", sch[i].student[j]);
                if(j != sch[i].num - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}