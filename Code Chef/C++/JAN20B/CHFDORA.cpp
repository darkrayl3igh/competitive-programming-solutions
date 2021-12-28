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
    int t,n,m,maxlimit,limit;
    long int answer;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vi > matrix(n , vector<int> (m));
        answer=n*m;
        maxlimit=min(n,m);
        maxlimit%2 ? 1 : maxlimit--;
        maxlimit/=2;
        f(i,0,n) f(j,0,m) cin>>matrix[i][j];
        f(i,1,n-1)
        {
            f(j,1,m-1)
            {
                limit=1;
                while(limit<=maxlimit && limit<=min(i,j) && limit<=min(n-i-1,m-j-1))
                {
                    if(matrix[i-limit][j]==matrix[i+limit][j] && matrix[i][j-limit]==matrix[i][j+limit]){answer++; limit++;}
                    else break;
                }
            }
        }
        cout<<answer<<endl;

    }
    return 0;
}

