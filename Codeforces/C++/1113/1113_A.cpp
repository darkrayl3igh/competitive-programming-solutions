// https://codeforces.com/problemset/problem/1113/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v;
    cin>>n>>v;
    if(v>=n-1)
        cout<<n-1;
    else
        cout<<((n-v)*(n-v+1)/2)-1+v;
    return 0;
}