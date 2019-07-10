#include <cstring>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    int team, person, grade;
    map<int, int> team_score;
    for(int i = 0; i < N; i++){
        scanf("%d-%d %d", &team, &person, &grade);
        if(team_score.count(team) == 0)
            team_score[team] = 0;
        team_score[team] += grade;
    }
    map<int, int>::iterator it;
    int max = 0, result;
    for(it = team_score.begin(); it != team_score.end(); it++){
        if(it -> second > max){
            max = it -> second;
            result = it -> first;
        }
    }
    printf("%d %d", result, max);
    return 0;
}