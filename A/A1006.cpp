#include <iostream>
#include <stdio.h>
using namespace std;

struct sign{
    char id[20];
    int time_in_h;
    int time_in_m;
    int time_in_s;
    int time_out_h;
    int time_out_m;
    int time_out_s;
}temp, in_first, out_last;

int compare_in(sign a, sign b){
    if(a.time_in_h < b.time_in_h)
        return 1;
    else if(a.time_in_h == b.time_in_h){
        if(a.time_in_m < b.time_in_m)
            return 1;
        else if(a.time_in_m == b.time_in_m){
            if(a.time_in_s < b.time_in_s)
                return 1;
            else    
                return 0;
        }
        else 
            return 0;
    }
    else 
        return 0;
}
int compare_out(sign a, sign b){
    if(a.time_out_h < b.time_out_h)
        return 1;
    else if(a.time_out_h == b.time_out_h){
        if(a.time_out_m < b.time_out_m)
            return 1;
        else if(a.time_out_m == b.time_out_m){
            if(a.time_out_s < b.time_out_s)
                return 1;
            else    
                return 0;
        }
        else 
            return 0;
    }
    else 
        return 0;
}


int main(){
    int i, N;
    cin >> N;
    in_first.time_in_h = 23;
    in_first.time_in_m = 59;
    in_first.time_in_s = 59;
    out_last.time_in_h = 0;
    out_last.time_in_m = 0;
    out_last.time_in_s = 0;
    for(i=0;i<N;i++){
        scanf("%s%02d:%02d:%02d%02d:%02d:%02d", temp.id, &temp.time_in_h, &temp.time_in_m, &temp.time_in_s, &temp.time_out_h, &temp.time_out_m, &temp.time_out_s);
        if(compare_in(temp, in_first))
            in_first = temp;
        if(compare_out(out_last, temp))
            out_last = temp;
    }
    printf("%s %s", &in_first.id, &out_last.id);
    return 0;
}