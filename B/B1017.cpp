#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
struct bign{
    int len;
    int d[1000];
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign trans(char a[]){
    int len = strlen(a);
    bign n;
    n.len = len;
    int p = 0;
    for(int i = len - 1; i >= 0; i--){
        n.d[p++] = a[i] - '0';
    }
    return n;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
    return;
}

bign div(bign a, int b, int& r){
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;
        else{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

int main(){
    char a[1000];
    int n;
    scanf("%s %d", a, &n);
    int r = 0;
    bign temp = trans(a);
    temp = div(temp, n, r);
    print(temp);
    printf(" %d", r);
    return 0;
}