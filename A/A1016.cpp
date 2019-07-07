#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct record{
    char name[30];
    int month;
    int day;
    int hour;
    int minute;
    char state[10];
}rec[1010];
bool cmp(record a, record b){
    if(a.month != b.month) return a.month < b.month;
    else if(a.day != b.day) return a.day < b.day;
    else if(a.hour != b.hour) return a.hour < b.hour;
    else if(a.minute != b.minute) return a.minute < b.minute;
}
bool cmp_name(record a, record b){
    return strcmp(a.name, b.name) < 0;
}
int cal_time(record a, record b){
    int minutes = (a.day * 24 * 60 + a.hour * 60 + a.minute) - (b.day * 24 * 60 + b.hour * 60 + b.minute);
    return -minutes;
}
double cal_money(record a, record b, int rate[]){
    double sum = 0;
    do{
        b.minute--;
        if(b.minute < 0){
            b.hour--;
            b.minute = 59;
        }
        if(b.hour < 0){
            b.day--;
            b.hour = 23;
        }
        sum += rate[b.hour];
    }while(!(a.hour == b.hour && a.day == b.day && a.minute == b.minute));
    return sum / 100.0;
}
int main(){
    int rate[24];
    for(int i = 0; i < 24; i++)
        scanf("%d", &rate[i]);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute, rec[i].state);
    }
    sort(rec, rec + N, cmp_name);
    int count = 1, p = 0;
    bool is_first = true;
    int time;
    double money, amount = 0.0;
    for(int i = 1; i < N ; i++){
        if(strcmp(rec[i].name, rec[i - 1].name) == 0 && i != N - 1){
            count++;
        }
        else {
            if(i == N - 1)
                count++;
            sort(rec + p, rec + p + count, cmp);//rec + p为当前名字人的第一条记录，count为这个人的总记录数
            for(int j = p; j < p + count - 1; j++){
                if((strcmp(rec[j].state, "on-line") == 0) && (strcmp(rec[j + 1].state, "off-line") == 0) && (strcmp(rec[j].name, rec[j + 1].name) == 0)){
                    if(is_first){
                        printf("%s %02d\n", rec[j].name, rec[j].month);
                        is_first = false;
                    }
                    time = cal_time(rec[j], rec[j + 1]);
                    money = cal_money(rec[j], rec[j + 1], rate);
                    amount += money;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", rec[j].day, rec[j].hour, rec[j].minute, rec[j + 1].day, rec[j + 1].hour, rec[j + 1].minute, time, money);                    
                }
            }
            if(!is_first)
                printf("Total amount: $%.2f\n", amount);
            amount = 0.0;
            is_first = true;
            p = p + count;
            count = 1;
        }
    }
    return 0;
}