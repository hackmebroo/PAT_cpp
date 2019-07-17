#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 0x7fffffff;
int main(){
    int m, n;
    scanf("%d", &m);
    int str1[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &str1[i]);
    str1[m] = inf;
    scanf("%d", &n);
    int temp, end = (m + n - 1) / 2, j = 0, k = 0, index = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        if(index < end){
            if(temp <= str1[j]){
                index++;
            }
            else{
                while(str1[j] < temp && index < end){
                    j++;
                    index++;
                }
                if(index == end){
                    if(temp > str1[j]){
                        printf("%d", str1[j]);
                        return 0;
                    }
                    else {
                        printf("%d", temp);
                        return 0;
                    }
                }
                index++;
            }
        }
        else{
            if(temp > str1[j]){
                printf("%d", str1[j]);
                return 0;
            }
            else {
                printf("%d", temp);
                return 0;
            }
        }
    }
    printf("%d", str1[j + end - index]);
    return 0;
}