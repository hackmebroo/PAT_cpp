#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct info{
    char id[10];
    char name[10];
    int grade;
}stu[100010];
bool cmp1(info a, info b){
    return strcmp(a.id, b.id) < 0;
}
bool cmp2(info a, info b){
    if(strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else return strcmp(a.id, b.id) < 0;
}
bool cmp3(info a, info b){
    if(a.grade != b.grade) return a.grade < b.grade;
    else return strcmp(a.id, b.id) < 0;
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
    if(M == 1)
        sort(stu, stu + N, cmp1);
    else if(M == 2)
        sort(stu, stu + N, cmp2);
    else 
        sort(stu, stu + N, cmp3);
    for(int i = 0; i < N; i++)
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    return 0;
}