// https://codeforces.com/problemset/problem/155/A
#include <bits/stdc++.h>

using namespace std;

int n,a,amax=INT_MIN,amin=INT_MAX,amazing=-2;

int main(){

    cin>>n;
    while(n--){
        cin>>a;
        if(a>amax){amazing++;amax=a;}
        if(a<amin){amazing++;amin=a;}
    }
    cout<<amazing;
    return 0;
}