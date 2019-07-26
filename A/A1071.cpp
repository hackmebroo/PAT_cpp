#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

bool check(char a){
    if(a >= '0' && a <= '9') return true;
    else if(a >= 'a' && a <= 'z') return true;
    else if(a >= 'A' && a <= 'Z') return true;
    else return false;
}

int main(){
    map<string, int> count;
    string str;
    getline(cin, str);
    int i = 0, len = str.length();
    while(i < len){
        string word;
        while(i < len && check(str[i])){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
            word += str[i];
            i++;
        }
        if(word != " "){
            if(count.find(word) != count.end()) count[word]++;
            else count[word] = 1;
        }
        while(i < len && !check(str[i]))
            i++;
    }
    string ans;
    int max = 0;
    for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
        if(it -> second > max){
            max = it -> second;
            ans = it -> first;
        }
    }
    cout << ans << " " << max << endl;
    return 0;
}