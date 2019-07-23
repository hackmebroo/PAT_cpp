#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct bign{
    int len;
    int d[25];
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
    bign b;
    int sign = 0;
    for(int i = 0; i < a.len; i++){
        int temp = a.d[i] + a.d[i] + sign;
        b.d[b.len++] = temp % 10;
        sign = temp / 10;
    }
    if(sign != 0)
        b.d[b.len++] = sign;
    return b;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.d[i]);
    }
    return;
}

int main(){
    char a[25];
    scanf("%s", a);
    bign b = trans(a);
    b = add(b);
    int hash[10] = {};
    int len = strlen(a);
    if(len != b.len){
        printf("No\n");
        print(b);
        return 0;
    }
    for(int i = 0; i < len; i++)
        hash[a[i] - '0']++;
    for(int i = 0; i < len; i++){
        hash[b.d[i]]--;
        if(hash[b.d[i]] < 0){
            printf("No\n");
            print(b);
            return 0;
        }
    }
    printf("Yes\n");
    print(b);
    return 0;
}