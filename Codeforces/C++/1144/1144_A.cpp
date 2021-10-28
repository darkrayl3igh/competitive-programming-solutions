// https://codeforces.com/problemset/problem/1144/A
//Galatians 4:16

#include <bits/stdc++.h>

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define vi vector<int>
#define newline cout<<endl;
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

const double pi = 3.1415926535;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int main()
{
    sonic
    int n,l,r,flag;
    string s;
    cin>>n;
    f(i,0,n)
    {
        vi alpha(26);
        flag=1;
        cin>>s;
        f(j,0,s.size()) alpha[s[j]-'a']++;
        f(j,0,26)
        {
            //cout<<alpha[j]<<" ";
            if(alpha[j]!=0) r=j;
        }
        f(j,0,26)
        {
            if(alpha[j]!=0){ l=j;break; }
        }
        //cout<<endl;
        f(j,l,r+1)
        {
            //cout<<alpha[j]<<" ";
            if(alpha[j]>1||alpha[j]==0) flag=0;
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}