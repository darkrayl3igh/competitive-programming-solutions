//https://codeforces.com/contest/1593/problem/D1
#include <bits/stdc++.h>
#define ll long long int
#define F(i, a, n) for (ll i = a; i < n; i++)
#define pb push_back
#define NL "\n"
#define dd double
#define __ ' '
#define mp make_pair
#define fi first
#define se second
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define ull unsigned int long long
const int INF = INT_MAX;
#define INFL LLONG_MAX
#define f_scan ios_base::sync_with_stdio(!cin.tie(0))
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
#define deci(n) fixed << setprecision(n)
using namespace std;

int32_t main()
{

    f_scan;
    
    tc{
      ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll res=0;
        for(ll i = 0 ; i < n ; i++) {
            if(i==0)continue;
            res=__gcd(res,a[i]-a[i-1]);
        }
         res = res==0?-1:res;
        cout << res << NL;
        
    }
    
    return 0;
}
