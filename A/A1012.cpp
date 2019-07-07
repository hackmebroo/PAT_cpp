#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct grade{
    char id[10];
    int C;
    int M;
    int E;
    int average;
}stu[2010];
bool cmpA(grade a, grade b){
    if(a.average != b.average) return a.average > b.average;
    else return strcmp(a.id, b.id) < 0;
}
bool cmpC(grade a, grade b){
    if(a.C != b.C) return a.C > b.C;
    else return strcmp(a.id, b.id) < 0;
}
bool cmpM(grade a, grade b){
    if(a.M != b.M) return a.M > b.M;
    else return strcmp(a.id, b.id) < 0;
}
bool cmpE(grade a, grade b){
    if(a.E != b.E) return a.E > b.E;
    else return strcmp(a.id, b.id) < 0;
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s %d %d %d", stu[i].id, &stu[i].C, &stu[i].M, &stu[i].E);
        stu[i].average = (stu[i].C + stu[i].M + stu[i].E) / 3;    
    }
    char temp[10];
    for(int i = 0; i < M; i++){
        int tempA = 1, tempC = 1, tempM = 1, tempE = 1;
        int rank = 1, pos = 1, count = 0;
        scanf("%s", temp);
        for(int j = 0; j < N; j++){
            if(strcmp(stu[j].id, temp) == 0){
                count++;
                break;
            }
        }
        if(count == 0){
            printf("N/A\n");
            continue;
        }
        //判断是否有这个人
        sort(stu, stu + N, cmpA);
        for(int j = 1; j < N; j++){
            if(stu[j].average == stu[j - 1].average)
                pos++;
            else{
                pos++;
                rank = pos;
            }
            if(strcmp(stu[j].id, temp) == 0){
                tempA = rank;
                break;
            }
        }
        //average排名
        rank = 1, pos = 1;
        sort(stu, stu + N, cmpC);
        for(int j = 1; j < N; j++){
            if(stu[j].C == stu[j - 1].C)
                pos++;
            else{
                pos++;
                rank = pos;
            }
            if(strcmp(stu[j].id, temp) == 0){
                tempC = rank;
                break;
            }
        }
        //C排名
        rank = 1, pos = 1;
        sort(stu, stu + N, cmpM);
        for(int j = 1; j < N; j++){
            if(stu[j].M == stu[j - 1].M)
                pos++;
            else{
                pos++;
                rank = pos;
            }
            if(strcmp(stu[j].id, temp) == 0){
                tempM = rank;
                break;
            }
        }
        //M排名
        rank = 1, pos = 1;
        sort(stu, stu + N, cmpE);
        for(int j = 1; j < N; j++){
            if(stu[j].E == stu[j - 1].E)
                pos++;
            else{
                pos++;
                rank = pos;
            }
            if(strcmp(stu[j].id, temp) == 0){
                tempE = rank;
                break;
            }
        }
        //E排名
        if(tempA <= tempC && tempA <= tempM && tempA <= tempE)
            printf("%d A\n", tempA);     
        else if(tempC <= tempA && tempC <= tempM && tempC <= tempE)
            printf("%d C\n", tempC);
        else if(tempM <= tempA && tempM <= tempC && tempM <= tempE)
            printf("%d M\n", tempM);
        else 
            printf("%d E\n", tempE);
    }
    return 0;                                       
}