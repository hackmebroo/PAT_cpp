#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int i,j,num;
    char c;
    cin >> num >> c;
    int num_row = (num + 1) / 2 ;
    // if(num % 2 == 0)
    //     num_row = num / 2;
    // else 
    //     num_row = num / 2 + 1;
    for(i=0;i<num_row;i++){
        if(i == 0)
            for(j=0;j<num;j++)
                cout << c;
        else if(i == num_row - 1){
            cout << endl;
            for(j=0;j<num;j++)
                cout << c;
        }
        else{
            cout << endl;
            for(j=0;j<num;j++){
                if(j == 0 | j == num - 1)
                    cout << c;
                else 
                    cout << ' ';
            }
        }

    }
    return 0;
}