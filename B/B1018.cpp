#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, N;
    cin >> N;
    char in[N][2];
    for(i=0;i<N;i++)
        cin >> in[i][0] >> in[i][1];
    int win = 0, tie = 0, lose = 0;
    int b1 = 0, j1 = 0, c1 = 0, b2 = 0, j2 = 0, c2 = 0;
    for(i=0;i<N;i++){
        if(in[i][0] == in[i][1])
            tie++;
        else if((in[i][0] == 'J' && in[i][1] == 'B') || (in[i][0] == 'C' && in[i][1] == 'J') || (in[i][0] == 'B' && in[i][1] == 'C')){
            win++;
            if(in[i][0] == 'J')
                j1++;
            else if(in[i][0] == 'B')
                b1++;
            else
                c1++;
        }
        else{
            lose++;
            if(in[i][1] == 'J')
                j2++;
            else if(in[i][1] == 'B')
                b2++;
            else
                c2++;
        }
    } 
    printf("%d %d %d\n", win, tie, lose);
    printf("%d %d %d\n", lose, tie, win);
    if(b1 >= c1){
        if(b1 >= j1)
            printf("B ");
        else
            printf("J ");
    }
    else{
        if(c1 >= j1)
            printf("C ");
        else
            printf("J ");
    }
    if(b2 >= c2){
        if(b2 >= j2)
            printf("B");
        else
            printf("J");
    }
    else{
        if(c2 >= j2)
            printf("C");
        else
            printf("J");
    }
}