#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 110;
typedef long long LL;
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
void showfraction(fraction a){
    a = reduction(a);
    // if(a.up < 0) printf("-");
    if(a.down == 1) printf("%lld", a.up);
    else if(abs(a.up) > a.down) printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down); 
    else printf("%lld/%lld", a.up, a.down);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld/%lld", &fra[i].up, &fra[i].down);
    sum.up = 0;
    sum.down = 1;
    for(int i = 0; i < n; i++){
        sum = fractionsum(sum, fra[i]);
    }
    showfraction(sum);
    return 0;
}