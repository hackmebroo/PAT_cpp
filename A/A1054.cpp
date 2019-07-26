#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main(){
    int m, n, temp;
    map<int, int> count;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &temp);
            // printf("%d ", temp);
            if(count.find(temp) != count.end()) count[temp]++;
            else count[temp] = 1;
        }
    }
    int max = 0, k;
    for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
        if(it -> second > max){
            k = it -> first;
            max = it -> second;
        }
    }
    printf("%d", k);
    return 0;
}