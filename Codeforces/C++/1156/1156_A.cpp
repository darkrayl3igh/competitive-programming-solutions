// https://codeforces.com/problemset/problem/1156/A
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
    int n,a,b,answer=0;
    vi series;
    bool flag=false;
    sonic
    cin>>n;
    f(i,0,n)
    {
        cin>>a;
        if(b==2&&a==3 || b==3&&a==2) flag=true;
        b=a;
        series.pb(a);
    }
    if(flag) {cout<<"Infinite"; return 0;}
    f(i,0,n)
    {
        if ( series[i]==1 && series[i+1]==2 ) {if( i>0 && series[i-1]==3 ) {answer+=2;} else answer+=3;}
        if ( series[i]==1 && series[i+1]==3 ) answer+=4;
        if ( series[i]==2 && series[i+1]==1 ) answer+=3;
        if ( series[i]==3 && series[i+1]==1 ) answer+=4;
    }
    cout<<"Finite\n"<<answer;
    return 0;
}