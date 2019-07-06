#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
struct grade{
    char reg_num[15];
    int grade;
    int location;
    int local_rank;
}stu[30010];
bool cmp1(grade a, grade b){
    if(a.grade != b.grade) return a.grade > b.grade;
    else return strcmp(a.reg_num, b.reg_num) < 0;
}
int main(){
    int N;
    scanf("%d", &N);
    int num[N], sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
        for(int j = sum; j < sum + num[i]; j++){
            scanf("%s %d", stu[j].reg_num, &stu[j].grade);
            stu[j].location = i + 1;
        } 
        sort(stu + sum, stu + sum + num[i], cmp1);

        stu[sum].local_rank = 1;
        int rank = 1, temp = 1;
        for(int j = sum + 1; j < sum + num[i]; j++){
            if(stu[j].grade == stu[j - 1].grade){
                temp++;
                stu[j].local_rank = rank;
            }
            else {
                temp++;
                rank = temp;
                stu[j].local_rank = rank;
            }
        }
        sum += num[i];
    }
    sort(stu, stu + sum, cmp1);
    int rank = 1, temp = 1;
    printf("%d\n", sum);
    printf("%s 1 %d %d\n", stu[0].reg_num, stu[0].location, stu[0].local_rank);
    for(int i = 1; i < sum; i++){
        if(stu[i].grade == stu[i - 1].grade){
            temp++;
            printf("%s %d %d %d\n", stu[i].reg_num, rank, stu[i].location, stu[i].local_rank);
        }
        else{
            temp++;
            rank = temp;
            printf("%s %d %d %d\n", stu[i].reg_num, rank, stu[i].location, stu[i].local_rank);
        }
    }
    return 0;
}