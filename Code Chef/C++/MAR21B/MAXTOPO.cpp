// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

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

const ll N = (ll) 5e5 + 5;
ll n;

ll inv_fact[N + 1];
ll inv_N[N + 1];
ll fact[N + 1];

vector <vector <ll>> adj;
vector <ll> visited, no_of_perm, subtree;
vector <pair <ll, pair <ll, ll>>> tracker;

void inv_N_gen (){
    inv_N[0] = inv_N[1] = 1;
    for (ll i = 2; i <= N; i++) inv_N[i] = inv_N[MOD % i] * (MOD - MOD / i) % MOD;
}

void inv_fact_gen(){
    inv_fact[0] = inv_fact[1] = 1;
    for (ll i = 2; i <= N; i++) inv_fact[i] = (inv_N[i] * inv_fact[i - 1]) % MOD;
}

void fact_gen(){
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

ll ncs(ll n, ll r) {
    if(r > n){
        return 0;
    }
    if(r == n){
        return 1;
    }
    ll toReturn = ((fact[n] * inv_fact[r]) % MOD * inv_fact[n - r]) % MOD;
    return toReturn;
}

ll DFS(ll node) {
    visited[node] = 1;
    ll ans = 1, subTree = 0;
    for(auto x: adj[node]) {
        if(visited [x] == 0) {
            ll curr = DFS(x);
            subTree += curr;
            
            ans *= ncs(subTree, curr);
            ans %= MOD;
            ans *= no_of_perm[x];
            ans %= MOD;
        }
    }
    ans %= MOD;
    no_of_perm[node] = ans;
    return subTree+1;
}

ll get_node(ll node){
    visited [node] = 1;
    ll subTree = 0, currNode;
    for(auto x: adj[node]) {
        if(visited [x] == 0) {
            currNode = get_node(x);
            subTree += currNode;
            ll temp = min(currNode, (n - currNode));
            tracker.pb({temp, {x, node}});
        }
    }
    subtree[node] = subTree + 1;
    return subTree + 1;
}

void solve(){   
    ll k; cin >> n >> k;
    ll m = n - 1;

    adj.clear();
    visited .clear();
    no_of_perm.clear();
    
    adj.resize(n);
    visited.resize(n, 0);
    no_of_perm.resize(n);
    
    while(m--) {
        ll u, v; cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    if(n == 1){
        visited.clear();
        no_of_perm.clear();
        visited.resize(n, 0);
        no_of_perm.resize(n);
        DFS(0);
        cout << 1 << " " << no_of_perm[0] % MOD << "\n";
        return;
    }

    tracker.clear();
    subtree.clear();
    subtree.resize(n);
    
    get_node(0);
    ll itr = 1;
    sort(all(tracker), greater<pair<ll, pair<ll, ll>>>());
    
    ll temp1, temp2;
    if(tracker[0].first != tracker[1].first){        
        ll U = tracker[0].second.first;
        ll V = tracker[0].second.second;
        if(subtree[U] == n - subtree[U]) {
            temp1 = max(U, V);
            temp2 = min(U, V);
        } 
        else{
            if(subtree[U] > n - subtree[U]){
                temp1 = U;
                temp2 = V;
            } 
            else{
                temp2 = U;
                temp1 = V;
            }
        }
    } 
    else{
        vector<ll> dp;
        
        if((tracker[0].second.first == tracker[1].second.first) || (tracker[0].second.first == tracker[1].second.second)) {
            temp1 = tracker[0].second.first;
        } 
        else{
            temp1 = tracker[0].second.second;
        }
        
        itr = 1;

        if(tracker[0].second.first != temp1){
            dp.pb(tracker[0].second.first);
        }
        else{
            dp.pb(tracker[0].second.second);
        }
        
        while(itr != n && tracker[itr-1].first == tracker[itr].first){
            if ((tracker[itr].second.first != temp1)){
                dp.pb(tracker[itr].second.first);
            }
            else {
                dp.pb(tracker[itr].second.second);   
            }
            ++itr;
        }
        temp2 = *max_element(all(dp));
    }
    

    if (k == 1){
        visited.clear();
        no_of_perm.clear();
        visited.resize(n, 0);
        no_of_perm.resize(n);
        DFS(temp1);
        cout << temp1 + 1 << " " << ((no_of_perm[temp1] % MOD) + MOD) % MOD << "\n";
    } 
    else{
        visited.clear();
        no_of_perm.clear();
        visited.resize(n, 0), no_of_perm.resize(n);
        DFS(temp2);
        cout << temp2 + 1 << " " << ((no_of_perm[temp2] % MOD) + MOD) % MOD << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    fact_gen ();
    inv_N_gen ();
    inv_fact_gen ();

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}