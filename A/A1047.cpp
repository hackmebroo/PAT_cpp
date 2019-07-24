#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> student[M];
int getID(char a[]){
    int id = 0;
    for(int i = 0; i < 3; i++){
        id *= 26;
        id += a[i] - 'A';
    }
    id *= 10;
    id += a[3] - '0';
    return id;
}

void showstudent(int a){
    int temp[4];
    temp[3] = a % 10;
    a /= 10;
    for(int i = 2; i >= 0; i--){
        temp[i] = a % 26;
        a /= 26;
    }
    for(int i = 0; i < 3; i++){
        printf("%c", temp[i] + 'A');
    }
    printf("%c", temp[3] + '0');
    return;
}

int main(){
    int student_num_total, course_num_total;
    scanf("%d %d", &student_num_total, &course_num_total);
    for(int i = 0; i < student_num_total; i++){
        char temp[5];
        int course_num;
        scanf("%s %d", temp, &course_num);
        int id = getID(temp), course_id;
        for(int j = 0; j < course_num; j++){
            scanf("%d", &course_id);
            student[course_id].push_back(id);
        }
    }
    for(int i = 1; i <= course_num_total; i++){
        sort(student[i].begin(), student[i].end());
        printf("%d %d\n", i, student[i].size());
        for(int j = 0; j < student[i].size(); j++){
            showstudent(student[i][j]);
            printf("\n");
        }
    }
    return 0;
}