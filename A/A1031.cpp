#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int N = 0;
    char str[90];
    cin.getline(str, 90);
    N = strlen(str);
    int n2, n1, max = 0;
    for(n2=3;n2<=N+2;n2++){
        if((N - n2 + 2) % 2 != 0)
            continue;
        else{
            n1 = (N - n2 + 2) / 2;
            if(n1 >= max && n1 <= n2)
                max = n1;
        }
    }
    n1 = max;
    n2 = N + 2 - n1 - n1;
    int i, j, p1 = 0, p2 = N - 1;
    for(i=0;i<n1;i++){
        if(i != n1 - 1){
            for(j=0;j<n2;j++){
                if(j == 0){
                    printf("%c",str[p1]);
                    p1++;
                }
                else if(j == n2 - 1){
                    printf("%c\n",str[p2]);
                    p2--;
                }
                else 
                    printf(" ");
            }
        }
        else{
            for(j=0;j<n2;j++){
                printf("%c",str[p1]);
                p1++;
            }
        }
    }
    return 0;
}