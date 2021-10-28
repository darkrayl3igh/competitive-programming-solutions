// https://codeforces.com/problemset/problem/1287/C
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
    int n,totalevens,totalodds,value,parity,zeroes=0,evens=0,odds=0,flag=1,firstparity,answer=0, firstindex=0;
    vector<char> garland;
    garland.pb('Z');
    cin>>n;
    if(n%2==0)
    {
        totalevens=n/2; totalodds=n/2;
    }
    else
    {
        totalevens=n/2; totalodds=n/2+1;
    }
    f(i,0,n)
    {
        cin>>value;
        if(value==0)
        {
            garland.pb('N');
            zeroes++;
        }
        if(value!=0)
        {
            if(flag) {firstparity=value%2; flag=0; firstindex=i;}
            parity=value%2;
            if(parity) odds++;
            else evens++;
            garland.pb(parity ? 'O':'E');
        }
    }
    totalevens-=evens;
    totalodds-=odds;
    parity=firstparity;
    if(zeroes==n) {cout<<1; return 0;}

    for(int i=firstindex; i>0; i--)
    {
        if(parity)
        {
            if(totalodds>0){garland[i]='O'; totalodds--;}
            else if(totalevens>0){garland[i]='E'; totalevens--;}
        }
        else
        {
            if(totalevens>0){garland[i]='E'; totalevens--;}
            else if(totalodds>0){garland[i]='E'; totalodds--;}
        }
    }
    f(i,firstindex+1,garland.size())
    {
        if(garland[i]=='N')
        {
            if(parity)
            {
                if(totalodds>0){garland[i]='O'; totalodds--;}
                else if(totalevens>0){garland[i]='E'; totalevens--;}
            }
            else
            {
                if(totalevens>0){garland[i]='E'; totalevens--;}
                else if(totalodds>0){garland[i]='E'; totalodds--;}
            }
        }
        if(garland[i]=='O' && garland[i-1]=='E') parity=1;
        if(garland[i]=='E' && garland[i-1]=='O') parity=0;
    }
    f(i,1,garland.size()-1)
    {
        if(garland[i]!=garland[i+1]) answer++;
    }
    cout<<answer;

    return 0;
}