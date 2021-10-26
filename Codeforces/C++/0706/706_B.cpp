// https://codeforces.com/problemset/problem/706/B
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    ll n,q,a;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        cin>>a;
        ll j=upper_bound(v.begin(),v.end(),a)-v.begin();
        cout<<j<<"\n";
    }
}