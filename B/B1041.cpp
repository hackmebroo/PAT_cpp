#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, j, N;
    cin >> N;
    long long in[N][3];
    for(i=0;i<N;i++)
        cin >> in[i][0] >> in[i][1] >> in[i][2];
    int M;
    cin >> M;
    int find[M];
    for(i=0;i<M;i++)
        cin >> find[i];
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(in[j][1] == find[i])
                printf("%lld %d", in[j][0], in[j][2]);
        }
        if(i != M - 1)
            printf("\n");
    }
    return 0;
}