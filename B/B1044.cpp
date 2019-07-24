#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numtostr[170];
map<string, int> strtonum;

void init(){
    for(int i = 0; i < 13; i++){
        numtostr[i] = low[i];
        strtonum[low[i]] = i;
        numtostr[i * 13] = high[i];
        strtonum[high[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++){
        for(int j = 1; j < 13; j++){
            string str = high[i] + " " + low[j];
            numtostr[i * 13 + j] = str;
            strtonum[str] = i * 13 + j;
        }
    }
}

int main(){
    int n;
    init();
    scanf("%d", &n);
    getchar();
    while(n--){
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9'){
            int len = str.size();
            int num = 0;
            for(int j = 0; j < len; j++){
                num *= 10;
                num += str[j] - '0';
            }
            cout << numtostr[num] << endl;
        }
        else 
            cout << strtonum[str] << endl;
    }
    return 0;
}