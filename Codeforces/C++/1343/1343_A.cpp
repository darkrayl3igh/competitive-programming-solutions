// https://codeforces.com/problemset/problem/1343/A
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
    int t,flag,ans=-1;
    long int n;
    vector<ll> twos;
    f(i,2,33) twos.pb(pow(2,i)-1);

    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>n;
        f(i,1,sqrt(n)+1)
        {
            if(n%i==0)
            {
                f(j,0,twos.size())
                {
                    if(i==twos[j]) {flag=1; break;}
                }
                if(flag) {ans=n/i; break;}
                f(j,0,twos.size())
                {
                    if(n/i==twos[j]) {flag=1; break;}
                }
                if(flag) {ans=i; break;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}