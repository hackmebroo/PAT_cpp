#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct worth{
    char name[10];
    int age;
    int money;
}person[100010], valid[100010];
bool cmp_age(worth a, worth b){
    return a.age <= b.age;
}
bool cmp_worth(worth a, worth b){
    if(a.money != b.money) return a.money > b.money;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}
int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        scanf("%s %d %d", person[i].name, &person[i].age, &person[i].money);
    sort(person, person + N, cmp_worth);
    int age[300] = {};
    int p = 0;
    for(int i = 0; i < N; i++){
        if(age[person[i].age] < 100){
            age[person[i].age]++;
            valid[p] = person[i];
            p++;
        }
    }//选每个年龄出前100人
    int M, low, high;
    for(int i = 0; i < K; i++){
        scanf("%d %d %d", &M, &low, &high);
        printf("Case #%d:\n", i + 1);
        int count = 0;
        for(int j = 0; j < p && count < M; j++){
            if(valid[j].age >= low && valid[j].age <= high){
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].money);
                count++;
            }
        }
        if(count == 0)
            printf("None\n");
    }
    return 0;
}