#include <iostream>
#include <stdio.h>
using namespace std;

int judge(int *out, int count){
    int i;
    for(i=0;i<count/2;i++){
        if(out[i] == out[count - 1 - i]){
            if(i != count/2 - 1)
                continue;
            else 
                return 1;
        }
        else 
            return 0;
    }
}
   

int main(){
    int i, N, b;
    scanf("%d%d", &N, &b);
    int out[40] = {}, count=0;
    for(i=0;i<40;i++){
        if(N < b){
            out[i] = N % b;
            count = i + 1;
            break;
        }
        else{
            out[i] = N % b;
            N /= b;
        }
    }
    if(count == 1){
        printf("Yes\n");
        for(i=0;i<count;i++){
            printf("%d",out[count - 1 - i]);
            if(i != count - 1)
                printf(" ");
        }
    }
    else if(!judge(out, count)){
        printf("No\n");
        for(i=0;i<count;i++){
            printf("%d",out[count - 1 - i]);
            if(i != count - 1)
                printf(" ");
        }
    }
    else{
        printf("Yes\n");
        for(i=0;i<count;i++){
            printf("%d",out[count - 1 - i]);
            if(i != count - 1)
                printf(" ");
        }
    }
    return 0;
}