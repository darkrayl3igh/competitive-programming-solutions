// https://codeforces.com/problemset/problem/1343/B
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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if((n/2)%2==1) { cout<<"NO\n"; continue;}
        cout<<"YES\n";
        vector<int> evens;
        f(i,0,n/2) evens.pb((i+1)*2);
        f(i,0,n/2) cout<<evens[i]<<" ";
        f(i,0,n/2)
        {
            if(i<n/4) cout<<evens[i]-1<<" ";
            else cout<<evens[i]+1<<" ";
        }
        newline
    }
    return 0;
}