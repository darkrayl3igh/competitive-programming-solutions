// https://codeforces.com/problemset/problem/1284/B
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
    int n,m,l,maxli,minli,li,maxlipos,minlipos,answer=0,reducedsize=0;
    vi maxliv;
    vi minliv;
    cin>>n; m=n;
    f(i,0,n)
    {
        cin>>l;
        maxli=-1;
        minli=9999999;
        vi currentli;
        int flag=0;
        f(j,0,l)
        {
            cin>>li;
            if(maxli<=li)
            {
                maxlipos=j;
                maxli=li;
            }
            if(minli>li)
            {
                minlipos=j;
                minli=li;
            }
            currentli.pb(li);
        }
        f(i,0,currentli.size())
        {
            f(j,i+1,currentli.size())
            {
                if(currentli[i]<currentli[j]){flag=1; break;}
            }
            if(flag) break;
        }
        if(flag){answer+=2*m; answer--; m--;}
        else
        {
            minliv.pb(minli); maxliv.pb(maxli);
            reducedsize++;
        }
    }
    f(i,0,reducedsize)
    {
        f(j,i,reducedsize)
        {
                if(minliv[i]<maxliv[j]) answer++;
                if(i!=j) if(minliv[j]<maxliv[i]) answer++;
        }
    }
    cout<<answer;
    return 0;
}