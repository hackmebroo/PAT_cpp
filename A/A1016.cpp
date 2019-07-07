#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
struct recode{
    char name[30];
    int month;
    int day;
    int hour;
    int minute;
    char state[10];
}rec[1010];
bool cmp(recode a, recode b){
    if(a.month != b.month) return a.month < b.month;
    else if(a.day != b.day) return a.day < b.day;
    else if(a.hour != b.hour) return a.hour < b.hour;
    else if(a.minute != b.minute) return a.minute < b.minute;
}
int main(){
    int rate[24];
    for(int i = 0; i < 24; i++)
        scanf("%d", &rate[i]);
    int N;
    for(int i = 0; i < N; i++){
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
    }
}