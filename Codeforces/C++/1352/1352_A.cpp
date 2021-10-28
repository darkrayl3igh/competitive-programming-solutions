// https://codeforces.com/problemset/problem/1352/A
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

string zeroes(int n)
{
    string zeroes="";
    f(i,0,n) zeroes=zeroes+'0';
    return zeroes;
}

int main()
{
    sonic
    int t,len,counter;
    string num;
    cin>>t;
    while(t--)
    {
        counter=0;
        cin>>num;
        len=num.size();
        f(i,0,len) if(num[i]!='0') {counter++;}
        cout<<counter<<endl;
        f(i,0,len)
        {
            if(num[i]!='0')
                cout<<num[i]<<zeroes(len-1-i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}