#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 110;
typedef long long LL;
bool inf = false;
struct fraction{
    LL up, down;
}fra[maxn], sum, temp;
LL gcd(LL a, LL b){
    if(b == 0) return a;
    else return gcd(b, (a % b));
}
fraction reduction(fraction a){
    if(a.down < 0){
        a.up = -a.up;
        a.down = -a.down;
    }
    else if(a.up == 0) a.down = 1;
    else{
        LL d = gcd(abs(a.up), abs(a.down));
        a.up /= d;
        a.down /= d;
    }
    return a;
}
fraction fractionsum(fraction a, fraction b){
    temp.up = a.up * b.down + b.up * a.down;
    temp.down = a.down * b.down;
    return reduction(temp);
}
fraction fractionsub(fraction a, fraction b){
    temp.up = a.up * b.down - a.down * b.up;
    temp.down = a.down * b.down;
    return reduction(temp);
}
fraction fractionmul(fraction a, fraction b){
    temp.up = a.up * b.up;
    temp.down = a.down * b.down;
    return reduction(temp);
}
fraction fractiondiv(fraction a, fraction b){
    if(b.up == 0){
        inf = true;
        temp.up = 0;
        temp.down = 1;
        return temp;
    }
    temp.up = a.up * b.down;
    temp.down = a.down * b.up;
    return reduction(temp);
}
void showfraction(fraction a){
    a = reduction(a);
    if(a.up < 0){
        printf("(");
        if(a.down == 1) printf("%lld", a.up);
        else if(abs(a.up) > a.down) printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down); 
        else printf("%lld/%lld", a.up, a.down);
        printf(")");
    }
    else{
        if(a.down == 1) printf("%lld", a.up);
        else if(abs(a.up) > a.down) printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down); 
        else printf("%lld/%lld", a.up, a.down);
    }
}
int main(){
    scanf("%lld/%lld", &fra[0].up, &fra[0].down);
    scanf("%lld/%lld", &fra[1].up, &fra[1].down);
    fra[2] = fractionsum(fra[0], fra[1]);
    fra[3] = fractionsub(fra[0], fra[1]);
    fra[4] = fractionmul(fra[0], fra[1]);
    fra[5] = fractiondiv(fra[0], fra[1]);
    showfraction(fra[0]); printf(" + "); showfraction(fra[1]); printf(" = "); showfraction(fra[2]); printf("\n");
    showfraction(fra[0]); printf(" - "); showfraction(fra[1]); printf(" = "); showfraction(fra[3]); printf("\n");
    showfraction(fra[0]); printf(" * "); showfraction(fra[1]); printf(" = "); showfraction(fra[4]); printf("\n");
    if(inf){
        showfraction(fra[0]); printf(" / "); showfraction(fra[1]); printf(" = "); printf("Inf"); printf("\n");
    }
    else {
        showfraction(fra[0]); printf(" / "); showfraction(fra[1]); printf(" = "); showfraction(fra[5]); printf("\n");
    }
    return 0;
}