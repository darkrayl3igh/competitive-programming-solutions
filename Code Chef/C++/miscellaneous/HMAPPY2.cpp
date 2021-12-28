#include <bits/stdc++.h>
#define ull unsigned long long int
ull gcd (ull a, ull b) {return ( a ? gcd(b%a, a) : b );}
using namespace std;

int main()
{
    unsigned long long int k,n,ans;
    unsigned long long int a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>k;
        ans=(n/a + n/b - n/ ( (a*b) / gcd(a,b) ) );
        if(ans>=k){cout<<"Win\n";}
        else{cout<<"Lose\n";}
    }
    return 0;
}
