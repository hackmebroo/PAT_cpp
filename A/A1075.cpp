#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct student{
    int id;
    int score[6];
    int solve;
    bool flag;
    int total;
}stu[10010];
int N, K, M;
int full[6];
void init(){
    for(int i = 1; i <= N; i++){
        stu[i].id = i;
        stu[i].total = 0;
        stu[i].flag = false;
        stu[i].solve = 0;
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
}
bool cmp(student a, student b){
    if(a.total != b.total) return a.total > b.total;
    else if(a.solve != b.solve) return a.solve > b.solve;
    else return a.id < b.id;
}
int main(){
    scanf("%d %d %d", &N, &K, &M);
    init();
    for(int i = 1; i <= K; i++)
        scanf("%d", &full[i]);
    int temp_id, temp_problem, temp_score;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &temp_id, &temp_problem, &temp_score);
        if(temp_score != -1)
            stu[temp_id].flag = true;
        if(temp_score == -1 && stu[temp_id].score[temp_problem] == -1)
            stu[temp_id].score[temp_problem] = 0;
        if(temp_score == full[temp_problem] && stu[temp_id].score[temp_problem] < full[temp_problem])
            stu[temp_id].solve++;
        if(temp_score > stu[temp_id].score[temp_problem])
            stu[temp_id].score[temp_problem] = temp_score;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(stu[i].score[j] != -1)
                stu[i].total += stu[i].score[j];
        }
    }
    sort(stu + 1, stu + N + 1, cmp);
    int rank = 1;
    for(int i = 1; i <= N && stu[i].flag == true; i++){
        if(i > 1 && stu[i].total != stu[i - 1].total)
            rank = i;
        printf("%d %05d %d", rank, stu[i].id, stu[i].total);
        for(int j = 1; j <= K; j++){
            if(stu[i].score[j] == -1)
                printf(" -");
            else 
                printf(" %d", stu[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}