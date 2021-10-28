// https://codeforces.com/problemset/problem/1236/A
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
    int t,a,b,c,x,y;
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>a>>b>>c;
        if(c%2!=0) c--;
        if(b==0){cout<<0<<endl;continue;}
        while(b>0)
        {
            if(b%2!=0){x=b-1;y=1;}
            else{x=b;y=0;}
            while(y<b)
            {
                if(a>=x/2.0&&c>=y*2)
                {
                    ans=max(ans,int((1.5*x)+(3*y)));
                }
                x-=2;y+=2;
            }
        b--;
        }
        cout<<ans<<endl;
    }
    return 0;
}