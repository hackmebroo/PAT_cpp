#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string var ("abcdefghijklmn");
    const string dest ("1234");
    string dest2 ("567891234");
    var.replace (3,3, dest);
    cout << "1: " << var << endl;
    var = "abcdefghijklmn";
    var.replace (3,1, dest.c_str(), 1, 3);
    cout << "2: " << var << endl;
    var ="abcdefghijklmn";
    var.replace (3, 1, 5, 'x');
    cout << "3: " << var << endl;
    string::iterator itA, itB;
    string::iterator itC, itD;
    itA = var.begin();
    itB = var.end();
    var = "abcdefghijklmn";
    var.replace (itA, itB, dest);
    cout << "4: " << var << endl;
    itA = var.begin ();
    itB = var.end();
    itC = dest2.begin () +1;
    itD = dest2.end ();
    var = "abodefghijklmn";
    var.replace (itA, itB, itC, itD);
    cout << "5: " << var << endl;
    var = "abcdefghijklmn";
    var.replace (3, 1, dest.c_str(), 4); //这种方式会限定字符串替换的最大长度
    cout <<"6: " << var << endl;
    return 0;
}