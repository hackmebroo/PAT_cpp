#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    char in[1010];
    cin.getline(in, 1010);
    int i, len, out[10] = {};
    len = strlen(in);
    for(i=0;i<len;i++){
        out[in[i] - '0'] += 1;
    }
    for(i=0;i<10;i++){
        if(out[i] != 0)
            printf("%d:%d\n", i, out[i]);
    }
    return 0;
}