#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int n;          //有效位
string deal(string s, int &e){
    int k = 0;
    while(s.length() > 0 && s[0] == '0'){
        s.erase(s.begin());
    }
    if(s[0] == '.'){
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0'){
            s.erase(s.begin());
            e--;                //指数
        }
    }
    else {
        while(k < s.length() && s[k] != '.'){//寻找小数点
            k++;
            e++;
        }
        if(k < s.length())
            s.erase(s.begin() + k);         //把小数点删除
    }
    if(s.length() == 0)
        e = 0;
    int num = 0;
    k = 0;
    string res;
    while(num < n){
        if(k < s.length())
            res += s[k++];      //还有数字就加到res后面
        else 
            res += '0';         //若没有则加0
        num++;
    }
    return res;
}
int main(){
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3 == s4 && e1 == e2){
        cout << "YES 0." << s3 << "*10^" << e1 << endl; 
    }
    else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl; 
    }
    return 0;
}