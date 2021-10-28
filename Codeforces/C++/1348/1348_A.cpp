// https://codeforces.com/problemset/problem/1348/A
//Galatians 4:16

#include <bits/stdc++.h>

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define newline cout<<endl;
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

typedef long long int ll;

const double pi = 3.1415926535;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int main()
{
    sonic
    int t,n,split;
    unsigned long long int small_sum, big_sum;
    vector<ll> twos;
    f(i,1,31) twos.pb(pow(2,i));
    cin>>t;
    while(t--)
    {
        small_sum=0;
        big_sum=0;
        cin>>n;
        split=n/2 - 1;
        f(i,0,split) small_sum+=twos[i];
        f(i,split,n-1) big_sum+=twos[i];
        cout<<twos[n-1]+small_sum-big_sum<<endl;
    }
    return 0;
}