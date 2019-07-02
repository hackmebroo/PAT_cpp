#include <stdio.h>
#include <iostream>
using namespace std;
struct money{
    long long Galleon;
    int Sickle;
    int Knut;
}temp1, temp2, out;

int main(){
    scanf("%lld.%d.%d %lld.%d.%d", &temp1.Galleon, &temp1.Sickle, &temp1.Knut, &temp2.Galleon, &temp2.Sickle, &temp2.Knut);
    int  sign1 = 0, sign2 = 0;
    long long temp = 0;
    temp = temp1.Knut + temp2.Knut;
    if(temp >= 29){
        sign1 += 1;
        out.Knut = temp % 29;
    }
    else 
        out.Knut = temp;
    temp = temp1.Sickle + temp2.Sickle + sign1;
    if(temp >= 17){
        sign2 += 1;
        out.Sickle = temp % 17;
    }
    else 
        out.Sickle = temp;
    temp = temp1.Galleon + temp2.Galleon + sign2;
    out.Galleon = temp;
    printf("%lld.%d.%d", out.Galleon, out.Sickle, out.Knut);
    return 0;
}