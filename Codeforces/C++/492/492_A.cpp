// https://codeforces.com/problemset/problem/492/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i=0,k;
    cin>>n;
    while(n>0)
    {
        i++;
        k=(i*(i+1)/2);
        n-=k;
    }
    if(n<0) i--;
    cout<<i;
    return 0;
}