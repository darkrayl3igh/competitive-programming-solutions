// https://codeforces.com/problemset/problem/785/A
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
    int n,ans=0;
    string s;
    sonic
    cin>>n;
    f(i,0,n)
    {
        cin>>s;
        if(s[0]=='I') ans+=20;
        if(s[0]=='C') ans+=6;
        if(s[0]=='T') ans+=4;
        if(s[0]=='O') ans+=8;
        if(s[0]=='D') ans+=12;
    }
    cout<<ans;
    return 0;
}