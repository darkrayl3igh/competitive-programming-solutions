// https://codeforces.com/problemset/problem/489/B
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

    int m,s,r,optimumDigits=0,remainingDigits=0;
    vi answer;
    cin>>m>>s;
    if(s==0){ cout<<"-1 -1";return 0; }
    optimumDigits=s/9;
    if(s%9!=0) optimumDigits++;
    if(optimumDigits>m){cout<<"-1 -1";return 0;}
    remainingDigits=m-optimumDigits;
    s-=remainingDigits;
    f(i,0,s/9) answer.pb(9);
    r=s-(s/9)*9;
    if(r!=0){ answer.pb(r); }
    f(i,0,remainingDigits){ answer.pb(1); }
    for(int i=answer.size()-1;i>=0;i--) cout<<answer[i];
    if(answer.size()<m) f(i,0,m-answer.size()) cout<<0;
    cout<<" ";
    f(i,0,answer.size()) cout<<answer[i];
    if(answer.size()<m) f(i,0,m-answer.size()) cout<<0;
    return 0;
}