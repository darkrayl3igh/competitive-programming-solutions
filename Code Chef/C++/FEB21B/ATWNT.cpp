// GALATIANS 4:16

#include "bits/stdc++.h"

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

using namespace std;

const int MOD = 1000000007;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

int n, k;
const ll MXN = 2e5 + 2;
vector<ll> g[MXN];

ll res[MXN], leaves[MXN];
vector<pair<ll,ll>> tracker[MXN];
unordered_map<ll,vector<ll>*>  height[MXN];
int choose_sum[10000][111], Choose = 1;

void invoke(ll c, ll x);

void invoke(ll u){
    if(g[u].size() == 0){
        leaves[u]=1;
    }
    for(auto i : g[u]){
        invoke(i);
        leaves[u] += leaves[i];
    }
}

void invoke(ll u,ll lvl){
    if(g[u].size() == 0 || leaves[u] == 1) return;
    ll sz = g[u].size();
    if(g[u].size() == 1){
        if(tracker[g[u][0]].size() < tracker[u].size()){
           swap(tracker[g[u][0]], tracker[u]);
        }
        for(auto i : tracker[u]){
           tracker[g[u][0]].push_back(i);
        }
        swap(height[lvl+1], height[lvl]);
    } else{
        for(auto &i : height[lvl]){
            if (i.F % sz != 0){
                for(auto x:*i.S){
                    res[x] += i.F;
                }
            } else{
                height[lvl+1][i.F/sz] = i.S;
            }
        }
        for(auto &i : tracker[u]){
            if (i.F % sz != 0){
                res[i.S] += i.F;
            } else{
                if(height[lvl+1].count(i.F/sz) == 0){
                    height[lvl+1][i.F/sz] = new vector<ll>();
                }
                height[lvl+1][i.F/sz]->push_back(i.S);
            }
        }
    }

    for(auto i : g[u]){
        invoke(i,lvl+1);
    }
    if(g[u].size()==1){
        swap(height[lvl+1],height[lvl]);
    } else{
        for(auto &i : tracker[u]){
            if(i.F % sz == 0){
                height[lvl+1][i.F/sz]->pop_back();
            }
        }
    }
    
    height[lvl+1].clear();
}

void choosesum(int N, int B) {
    if (B < 0) return ;

    int b = B / 2;
    ll res = 0;
    if(b > 0){
        res = choose_sum[N][b - 1];
    }
    for(b = b*2; b <= B; b++){
        res += Choose;
    }
}

void solve() {
    ll n; cin >> n;
    ll min = INT_MAX, max = INT_MIN;
    for(ll i = 0;i < n-1; i++){
        ll eg; cin >> eg;
        g[eg].push_back(i+2);
    }
    choosesum(min,max);
    invoke(1);
    ll q; cin >> q;
    for(ll i = 0; i < q; i++){
        ll v, k; cin >> v >> k;
        tracker[v].pb({k, i});
    }
    invoke(1, 1);
    for(ll i = 0; i < q; i++){
        cout << res[i] << "\n";
    }
}

// #ifdef LOCAL // compile with -DLOCAL, chk -> fake chk
// #else
// #endif
// #define chk(...);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}