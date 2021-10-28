// https://codeforces.com/problemset/problem/1157/B
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
    string s,t;
    ll ans;
    int n,m,k;
	cin>>n>>s;
	vi a(20);
	f(i,1,9) cin>>a[i];
	bool flag=false;
	f(i,0,n)
	{
		if(a[s[i]-'0']>(s[i]-'0'))
		{
			flag=true;
			s[i]=char(a[s[i]-'0']+'0');
		}
		else
		{
			if(flag)
			{
				if(a[s[i]-'0']==(s[i]-'0'))continue;
				else break;
			}
			else continue;
		}
	}
	cout<<s;
    return 0;
}