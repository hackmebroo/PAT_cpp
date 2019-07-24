#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> student[M];

int getID(char a[]){
    int num = 0;
    num += a[0] - 'A'; num *= 26;
    num += a[1] - 'A'; num *= 26;
    num += a[2] - 'A'; num *= 10;
    num += a[3] - '0';
    return num;
}

int main(){
    int student_num_total, course_num;
    scanf("%d %d", &student_num_total, &course_num);
    int course_id, student_num;
    char temp[5];
    for(int i = 0; i < course_num; i++){
        scanf("%d %d", &course_id, &student_num);
        for(int j = 0; j < student_num; j++){
            scanf("%s", temp);
            int id = getID(temp);
            student[id].push_back(course_id);
        }
    }
    for(int i = 0; i < student_num_total; i++){
        scanf("%s", temp);
        int id = getID(temp);
        sort(student[id].begin(), student[id].end());
        printf("%s %d", temp, student[id].size());
        for(int j = 0; j < student[id].size(); j++){
            printf(" %d", student[id][j]);
        }
        printf("\n");
    }
    return 0;
}