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

const int MOD = 1e9+7;

ll gcd (ll a, ll b){return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp){
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    vector<vector<ll> > costs(10, vector<ll>(10, 1e12));

    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        costs[x][y] = w;
    }

    for(int p = 0; p < 10; p++) {
        costs[p][p] = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                costs[i][j] = min(costs[i][j], costs[i][p] + costs[p][j]);
            }
        }
    }

    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         cout << costs[i][j] << " ";
    //     }
    //     newline;
    // }
    // newline;

    vector<ll> suffix(n/2 + 1);
    for(int i = n/2 - 1; i >= 0; i--) {
        ll op_cost = LLONG_MAX;
        ll x = s[i] - '0', y = s[n - i - 1] - '0';
        for(int p = 0; p < 10; p++) {
            op_cost = min(op_cost, costs[x][p] + costs[y][p]);
        }
        suffix[i] = op_cost + suffix[i + 1];
    }

    if (suffix[0] > k) {
        cout << -1 << '\n';
        return;
    }

    ll pref = 0;
    string ans = string(n, '.');
    
    for (int i = 0; i < n/2; i++) {
        ll x = s[i] - '0', y = s[n - i - 1] - '0';
        for (ll d = 9; d >= 0; d--) {
            if (pref + costs[x][d] + costs[y][d] + suffix[i + 1] <= k) {
                ans[i] = (char)(d + '0');
                ans[n - i - 1] = (char)(d + '0');
                pref += costs[x][d] + costs[y][d];
                break;
            }
        }
    }

    if (n & 1ll) {
        ll x = s[n / 2] - '0';
        for (ll d = 9; d >= 0; d--) {
            if (pref + costs[x][d] <= k) {
                ans[n / 2] = (char)(d + '0');
                break;
            }
        }
    }

    cout << ans << '\n';
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