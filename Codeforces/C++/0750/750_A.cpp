// https://codeforces.com/problemset/problem/750/A
#include <bits/stdc++.h>

using namespace std;

int n,k,t,turns=0;

int main(){

    cin>>n>>k;
    t=240-k;
    for(int i=1;t>=0;i++){
        t=t-(5*i);
        turns=i;
    }
    if(turns-1>n){cout<<n;}
    else{cout<<turns-1;}
    return 0;
}