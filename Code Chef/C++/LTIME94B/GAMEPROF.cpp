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

void solve(){   
    ll n, mul; cin >> n >> mul;
    set<ll> entry, exit;

    vector<pair<pair<ll, ll> , ll> > schedule(n);

    for(ll i = 0; i < n; i++) {
        ll xi, yi, vi; cin >> xi >> yi >> vi;
        entry.insert(xi); exit.insert(yi);
        schedule[i] = mp(mp(xi, yi), vi);
    }

    ll ans = 0;
    for(auto i = entry.begin(); i != entry.end(); i++) {
        for(auto j = exit.begin(); j != exit.end(); j++) {
            ll start = *i, end = *j, temp_ans = 0;
            if(end >= start) {
                ll cost = mul * (end - start);
                for(ll k = 0; k < n; k++) {
                    if(start <= schedule[k].first.first && schedule[k].first.second <= end) temp_ans += schedule[k].second;
                }

                temp_ans = temp_ans - cost;
                ans = (ans > temp_ans) ? ans : temp_ans;
            }
        }
    }

    cout << ans << "\n";    
}

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