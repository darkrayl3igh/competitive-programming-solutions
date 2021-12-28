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
    string s;
    sonic
    cin>>t;
    while(t--)
    {
        vi alpha(26);
        int odd=0,even=0;
        cin>>s;
        f(i,0,s.size()) alpha[s[i]-97]++;
        f(i,0,26)
        {
            if(alpha[i]%2==0&&alpha[i]!=0) even++;
            else if(alpha[i]%2==1) odd++;
        }
        if(even==0&&odd==3){ cout<<"DPS"<<endl; continue; }
        if(odd==0){ cout<<"!DPS"<<endl; continue; }
        if(odd>2){ cout<<"!DPS"<<endl; continue;}
        if(odd%2==0&&even==0){ cout<<"DPS"<<endl; continue; }
        if(odd%2==1){ cout<<"DPS"<<endl; continue; }
    }
    return 0;
}

