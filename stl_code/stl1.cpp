#include <iostream>
#include <string>
using namespace std;

int main(){
    string str("12345678");
    char ch[] = "abcdefgh";
    string a;
    string str_1(str);
    string str_2(str,2,5);
    string str_3(ch,5);
    string str_4(5,'X');
    string str_5(str.begin(),str.end());
    cout << str << endl;
    cout << a << endl;
    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_3 << endl;
    cout << str_4 << endl;
    cout << str_5 << endl;
    cout << ch << endl;
    return 0;
}