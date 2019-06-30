#include <iostream>
#include <stdio.h>
using namespace std;

struct birth{
    char name[10];
    int y,m,d;
}temp, oldest, youngest;

int judge(birth x){
    if(x.y < 1814)
        return 0;
    else if(x.y > 2014)
        return 0;
    else if(x.y == 1814){
        if(x.m < 9)
            return 0;
        else if(x.m == 9){
            if(x.d < 6)
                return 0;
            else 
                return 1;
        }
        else
            return 1;
    }
    else if(x.y == 2014){
        if(x.m > 9)
            return 0;
        else if(x.m == 9){
            if(x.d >6)
                return 0;
            else 
                return 1;
        }
        else 
            return 1;
    }
    else 
        return 1;
}

int compare(birth a, birth b){
    if(a.y < b.y)
        return 1;
    else if(a.y == b.y){
        if(a.m < b.m)
            return 1;
        else if(a.m == b.m){
            if(a.d <= b.d)
                return 1;
            else 
                return 0;
        }
        else 
            return 0;
    }
    else 
        return 0;
}

int main(){
    int i, N, count = 0, max = -1;
    cin >> N;
    oldest.y = 2014;
    oldest.m = 9;
    oldest.d = 7; 
    youngest.y = 1814;
    youngest.m = 9;
    youngest.d = 5;
    for(i=0;i<N;i++){
        scanf("%s%d/%d/%d", temp.name, &temp.y, &temp.m, &temp.d);
        if(judge(temp)){
            count++;
            if(compare(temp, oldest))
                oldest = temp;
            if(compare(youngest, temp))
                youngest = temp;
        }
    }
    if(count != 0)
        printf("%d %s %s", count, oldest.name, youngest.name);
    else 
        printf("0");
    return 0;
}