#include <iostream>
#include <string>
using namespace std;
int main(){
    string A("aBcdef");
    string B("AbcdEf");
    string C("123456");
    string D("123dfg");
    int m = A.compare(B);
    int n = A.compare(1,5,B,1,5);
    int p = A.compare(1,5,B,4,2);
    int q = C.compare(0,3,D,0,3);
    cout<<"m="<<m<<",n="<<n<<",p="<<p<<",q="<<q<<endl;
    return 0;
}