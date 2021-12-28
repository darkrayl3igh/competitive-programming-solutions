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
    int t,n,answer=0;
    string s;
    sonic
    cin>>t;
    while(t--)
    {
        answer=0;
        cin>>n;
        cin>>s;
        f(i,0,n-1) {if( (s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u') && (s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u') ) answer++;}
        cout<<answer<<endl;
    }
    return 0;
}

