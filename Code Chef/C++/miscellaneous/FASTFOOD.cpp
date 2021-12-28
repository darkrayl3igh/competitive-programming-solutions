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
    int t;
    sonic
    cin>>t;
    while(t--)
    {
        ll n,A,B,mostProfit=-1;
        vi Chefland(1),temp,Chefabad(1);
        cin>>n;
        f(i,1,n+1)
        {
            cin>>A;
            Chefland.pb(Chefland[i-1]+A);
        }
        f(i,0,n)
        {
            cin>>B;
            temp.pb(B);
        }
        reverse(temp.begin(),temp.end());
        f(i,1,n+1)
        {
            Chefabad.pb(Chefabad[i-1]+temp[i-1]);
        }
        reverse(Chefabad.begin(),Chefabad.end());
        f(i,0,n+1) if(Chefabad[i]+Chefland[i]>mostProfit) mostProfit=Chefabad[i]+Chefland[i];
        cout<<mostProfit<<endl;
    }
    return 0;
}

