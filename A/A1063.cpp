#include <set>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    set<int> sets[n + 1];
    for(int i = 1; i <= n; i++){
        int num;
        scanf("%d", &num);
        for(int j = 0; j < num; j++){
            int temp;
            scanf("%d", &temp);
            sets[i].insert(temp);
        }
    }
    int queries;
    scanf("%d", &queries);
    for(int i = 0; i < queries; i++){
        int a, b, count = 0;
        scanf("%d %d", &a, &b);
        for(set<int>::iterator it = sets[b].begin(); it != sets[b].end(); it++){
            if(sets[a].find(*it) != sets[a].end())
                count++;
        }
        printf("%.1f%\n", count * 100.0 / (sets[a].size() + sets[b].size() - count));
    }
    return 0;
}