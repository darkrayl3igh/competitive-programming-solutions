//https://codeforces.com/contest/1593/problem/E
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
      ll n,k;
    cin>>n>>k;
    vector<ll> arr[n];
    vector<ll> a(n,0);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);
        a[u-1]++;
        a[v-1]++;
    }
    queue<int> q;
    int vis[n];
    for(ll i=0;i<n;i++){
        vis[i]=0;
        if(a[i]==1 || a[i]==0){
            vis[i]=1;
            q.push(i);
        }
    }
    int ans=n;
    while(ans>0 && k>0){
        queue<int> q1;
        while(!q.empty()){
            ans--;
            ll x=q.front();
            q.pop();
            for(auto i:arr[x]){
                a[i]--;
                if(a[i]==1 || a[i]==0 && vis[i]==0){
                    vis[i]=1;
                    q1.push(i);
                }
            }
        }
        q=q1;
        k--;
    }
    cout<<ans<<NL;
        
    }
    
    return 0;
}
