#include <iostream>
#include <stdio.h>
using namespace std;
struct grade{
    char name[16];
    char gender[4];
    char id[16];
    int grade;
}temp, highest, lowest;

int compare(grade a, grade b){
    if(a.grade > b.grade)
        return 1;
    else 
        return 0;
}

int main(){
    int i, N;
    cin >> N;
    lowest.grade = 101;
    highest.grade = -1;
    for(i=0;i<N;i++){
        scanf("%s%s%s%d", temp.name, temp.gender, temp.id, &temp.grade);
        if(*temp.gender == 'M'){
            if(compare(lowest, temp))
                lowest = temp;
        }
        else if(*temp.gender == 'F'){
            if(compare(temp, highest))
                highest = temp;
        }
    }
    int sign = 0;
    if(highest.grade != -1)
        printf("%s %s\n", highest.name, highest.id);
    else{
        printf("Absent\n");
        sign++;
    }
    if(lowest.grade != 101)
        printf("%s %s\n", lowest.name, lowest.id);
    else{
        printf("Absent\n");
        sign++;
    }
    if(sign == 0)
        printf("%d", highest.grade - lowest.grade);
    else 
        printf("NA");
    
}