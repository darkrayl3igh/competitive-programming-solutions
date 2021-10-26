// https://codeforces.com/problemset/problem/732/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p,k,r,shovels=1;
    cin>>k>>r;
    p=k;
    while(true)
    {
        if(k%10==r||k%10==0) break;
        else{k+=p;shovels++;}
    }
    cout<<shovels;
    return 0;
}