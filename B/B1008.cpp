#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int i, num, a;
    cin >> num >> a;
    int in[num];
    for(i=0;i<num;i++)
        cin >> in[i];
    if(a >= num)
        a %= num;
    for(i=0;i<num;i++){
        if(i < a)
            cout << in[num - a + i] << ' ';
        else{
            if(i != num - 1)
                cout << in[i - a] << ' ';
            else
                cout << in[i - a];
        }
    }
    return 0;
}