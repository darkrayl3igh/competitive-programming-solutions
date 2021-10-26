// https://codeforces.com/problemset/problem/379/A
#include <bits/stdc++.h>

using namespace std;

int a,b,went=0,hour=0;

int main(){

    cin>>a>>b;
    for(int hours=0;a>0;hours++){
        a--;
        went++;
        if(went%b==0){a++;}
        hour=hours;
    }
    cout<<hour+1;
    return 0;
}