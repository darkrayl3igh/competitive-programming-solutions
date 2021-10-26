// https://codeforces.com/problemset/problem/581/A
#include <bits/stdc++.h>

using namespace std;

int a,b;

int main()
{
    cin>>a>>b;
    cout<<min(a,b)<<" "<<(max(a,b)-min(a,b))/2;
    return 0;
}