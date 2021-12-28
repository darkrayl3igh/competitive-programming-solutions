// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << "\n"
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1000000007;
const int MXN = 100001;

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

vector<ll> graph[MXN], second_set;
ll sets_of_A[1000001], sets_of_B[1000001], connections[1000001];
ll A[MXN], B[MXN], partitions[MXN], on_hold[MXN], visited[MXN];

priority_queue<pair<ll,ll> > tracker;

ll N, S, decision;

void travel(ll node,ll val)
{
    visited[node]++;
    on_hold[node] = val;

    bool flag = true;

    for(ll child: graph[node]) {
        if(!visited[child]) {
            partitions[child] = node;
            travel(child, val+1);
            flag = false;
        }
    }

    if(flag) {
        tracker.push({val, node});
    }
}

void disconnect(ll node) {
    connections[A[node]] = 0;
    connections[B[node]] = 0;
    sets_of_A[A[node]] = 0;
    sets_of_A[B[node]] = 0;
    sets_of_B[A[node]] = 0;
    sets_of_B[B[node]] = 0;
}

int setter(ll node) {
    sets_of_B[B[node]]++;
    sets_of_A[A[node]]++;

    if(sets_of_A[A[node]] == sets_of_B[A[node]] && connections[A[node]] != 0) {
        connections[A[node]]--;
        decision--;
    } else if(connections[A[node]] == 0) {
        connections[A[node]]++;
        decision++;
    }

    if(sets_of_A[B[node]] == sets_of_B[B[node]] && connections[B[node]] != 0) {
        connections[B[node]]--;
        decision--;
    } else if(connections[B[node]] == 0) {
        connections[B[node]]++;
        decision++;
    }

    visited[node]++;
    second_set.pb(node);

    if(decision==0) {
        if(visited[partitions[node]] == 0 && node != 1) {
            tracker.push(mp(on_hold[partitions[node]], partitions[node]));
        }
        disconnect(node);
        return 1;
    }

    if(node == 1) {
        disconnect(node);
        return 0;
    }

    if(visited[partitions[node]] == 0) {
        if(setter(partitions[node]) == 1) {
            disconnect(node);
            return 1;
        }
    }

    disconnect(node);

    return 0;
}

void reset() {
    for(ll i = 0; i < N+1; i++) {
        graph[i].clear();
        A[i] = 0;
        B[i] = 0;
        partitions[i] = 0;
        on_hold[i] = 0;
    }

    while(!tracker.empty()) {
        tracker.pop();
    }
}

void solve(){
    cin >> N >> S;

    for(int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }


    for(int i = 1; i < N+1; i++) {
        cin >> A[i];
    }

    for(int i = 1; i < N+1; i++) {
        cin >> B[i];
    }

    for(ll i = 1; i < N+1; i++) {
        visited[i] = 0;
        partitions[i] = 0;
        on_hold[i] = 0;
    }

    travel(1, 1);

    for(ll i = 1; i < N+1; i++) {
        visited[i]=0;
    }

    bool flag = false;

    vector<vector<ll> > sets;

    while(!tracker.empty()) {
        pair<ll,ll> leaf = tracker.top();
        tracker.pop();

        if(visited[leaf.second]==0) {
            decision = 0;
            second_set.clear();

            if(setter(leaf.second)==0) {
                flag = true;
                break;
            } else {
                sets.pb(second_set);
            }

        }

    }

    if(flag) {
        cout << 0 << "\n";
        return;
    }

    if(S == 1) {
        cout << 1 << "\n";
        return;
    }

    ll ans = 1;

    for(ll i = 0; i < sets.size(); i++) {
        ll u = sets[i][0];
        ll l = sets[i][0];

        for(ll j = 1; j < sets[i].size(); j++) {

            if(on_hold[sets[i][j]] > on_hold[l]) {
                l = sets[i][j];
            }

            if(on_hold[sets[i][j]] < on_hold[u]) {
                u = sets[i][j];
            }
        }

        ll counter = 0;

        for(ll c: graph[l]) {
            if(c != partitions[l]) {
                counter++;
            }
        }

        ans = (ans * (counter+1)) % MOD;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
        reset();
    }
    return 0;
}