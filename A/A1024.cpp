#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct bign{
    int len;
    int d[100];
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

bign add(bign a){
    bign b, c;
    b.len = a.len;
    for(int i = 0; i < a.len; i++){
        b.d[i] = a.d[a.len - 1 - i];
    }
    int sign = 0;
    for(int i = 0; i < a.len; i++){
        int temp = a.d[i] + b.d[i] + sign;
        c.d[c.len++] = temp % 10;
        sign = temp / 10;
    }
    if(sign != 0)
        c.d[c.len++] = sign;
    return c;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.d[i]);
    }
    return;
}

bool ispali(bign a){
    for(int i = 0; i <= a.len / 2; i++){
        if(a.d[i] != a.d[a.len - 1 - i])
            return false;
    }
    return true;
}

int main(){
    char a[15];
    int n;
    scanf("%s %d", a, &n);
    bign b = trans(a);
    if(ispali(b)){
        print(b);
        printf("\n");
        printf("0");
        return 0;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        b = add(b);
        count++;
        if(count == n)
            break;
        if(ispali(b)){
            print(b);
            printf("\n");
            printf("%d", count);
            return 0;
        }
    }
    print(b);
    printf("\n");
    printf("%d", n);
    return 0;
}