// https://codeforces.com/problemset/problem/1144/B
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

typedef long long ll;

const double pi = 3.1415926535;

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int main()
{
    sonic
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    vi vo,ve;
	int count1=0,count2=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
		count1++;
		ve.push_back(a[i]);
		}
		if(a[i]%2!=0)
		{
		count2++;
		vo.push_back(a[i]);
		}
	}
	int c=abs(count1-count2);
	if(c==0 || c==1)
    {

        cout<<0<<endl;
		return 0;
    }
    sort(ve.begin(),ve.end());
	sort(vo.begin(),vo.end());
	int sum=0;
    if(count1>count2)
    {
    for(int i=0;i<ve.size()-vo.size()-1;i++)
        sum=sum+ve[i];
    cout<<sum;
    }
    if(count2>count1)
    {
    for(int i=0;i<vo.size()-ve.size()-1;i++)
        sum=sum+vo[i];
    cout<<sum;
    }
    return 0;
}