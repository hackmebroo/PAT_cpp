#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct grade{
    char id[10];
    int virtue;
    int talent;
    int total;
}temp, sage[100000], nobleman[100000], foolman[100000], smallman[100000];
bool cmp(grade a, grade b){
    if(a.total != b.total) return a.total > b.total;
    else if(a.virtue != b.virtue) return a.virtue > b.virtue;
    else return strcmp(a.id, b.id) < 0;
}
int main(){
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    for(int i = 0; i < N; i++){
        scanf("%s %d %d", temp.id, &temp.virtue, &temp.talent);
        if(temp.virtue >= H && temp.talent >= H){
            sage[p1] = temp;
            sage[p1].total = temp.talent + temp.virtue;
            p1++;
        }
        else if(temp.virtue < L || temp.talent < L)
            continue;
        else if(temp.virtue >= H && temp.talent < H){
            nobleman[p2] = temp;
            nobleman[p2].total = temp.virtue + temp.talent;
            p2++;
        }
        else if(temp.virtue < H && temp.talent < H && temp.virtue >= temp.talent){
            foolman[p3] = temp;
            foolman[p3].total = temp.virtue + temp.talent;
            p3++;
        }
        else {
            smallman[p4] = temp;
            smallman[p4].total = temp.virtue + temp.talent;
            p4++;
        }
    }
    sort(sage, sage + p1, cmp);
    sort(nobleman, nobleman + p2, cmp);
    sort(foolman, foolman + p3, cmp);
    sort(smallman, smallman + p4, cmp);
    int sum = p1 + p2 + p3 + p4;
    printf("%d\n", sum);
    for(int i = 0; i < p1; i++){
        printf("%s %d %d\n", sage[i].id, sage[i].virtue, sage[i].talent);
    }
    for(int i = 0; i < p2; i++){
        printf("%s %d %d\n", nobleman[i].id, nobleman[i].virtue, nobleman[i].talent);
    }
    for(int i = 0; i < p3; i++){
        printf("%s %d %d\n", foolman[i].id, foolman[i].virtue, foolman[i].talent);
    }
    for(int i = 0; i < p4; i++){
        printf("%s %d %d\n", smallman[i].id, smallman[i].virtue, smallman[i].talent);
    }
    return 0;
}