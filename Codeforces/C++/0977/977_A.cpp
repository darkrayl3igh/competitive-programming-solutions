// https://codeforces.com/problemset/problem/977/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,k;
    cin>>n>>k;
    while(k--)
    {
        if(n%10==0) n/=10;
        else n--;
    }
    cout<<n;
    return 0;
}