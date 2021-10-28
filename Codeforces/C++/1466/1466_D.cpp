// https://codeforces.com/problemset/problem/1466/D
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

bool myComp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

void solve(){
    ll n, sum = 0; cin >> n;
    vector<pair<int, int> > edges;
    for(int i = 0; i < n; i++){
        int w; cin >> w;
        sum += w;
        edges.pb({w, 0});
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        edges[a-1].second++;
        edges[b-1].second++;
    }

    cout << sum << " ";

    sort(edges.begin(), edges.end(), myComp);

    for(auto it = edges.begin(); it != edges.end(); it++){
        for(int i = 1; i < it->second; i++){
            sum += it->first;
            cout << sum << " ";
        }
    }
    newline;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}