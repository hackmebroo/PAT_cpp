#include <iostream>
#include <stdio.h>
using namespace std;
struct money{
    int Gallon;
    int Sickle;
    int Knut;
}P, A, change;

int judge(money a, money b){
    if(a.Gallon < b.Gallon)
        return 1;
    else if(a.Gallon == b.Gallon){
        if(a.Sickle < b.Sickle)
            return 1;
        else if(a.Sickle == b.Sickle){
            if(a.Knut <= b.Knut)
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

int cal(money a, money b){
    int temp1, temp2, need;
    temp1 = a.Gallon * 17 * 29 + a.Sickle * 29 + a.Knut;
    temp2 = b.Gallon * 17 * 29 + b.Sickle * 29 + b.Knut;
    need = temp2 - temp1;
    change.Knut = need % 29;
    change.Sickle = (need / 29) % 17;
    change.Gallon = need / (17 * 29); 
    return 0;
}

int main(){
    scanf("%d.%d.%d", &P.Gallon, &P.Sickle, &P.Knut);
    scanf("%d.%d.%d", &A.Gallon, &A.Sickle, &A.Knut);
    if(judge(P, A)){//钱够了
        cal(P, A);
        printf("%d.%d.%d", change.Gallon, change.Sickle, change.Knut);
    }
    else{
        cal(A, P);
        printf("-%d.%d.%d", change.Gallon, change.Sickle, change.Knut);
    }
    return 0;
}