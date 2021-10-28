// https://codeforces.com/problemset/problem/1118/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int n,a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(a*2>=b) cout<<(n/2*b) + ((n%2)*a);
        if(a*2<b) cout<<n*a;
        cout<<endl;
    }
    return 0;
}