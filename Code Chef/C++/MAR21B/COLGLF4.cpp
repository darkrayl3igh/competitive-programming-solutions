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

void solve() {
    int N, E, H, A, B, C; cin >> N >> E >> H >> A >> B >> C;
    ll ans = -1;

    vector<ll> prices, iv(N + 2);
    for(int i = 0; i <= N + 1; i++) iv[i] = i;

    for(int no_of_shakes = 0; no_of_shakes <= N; no_of_shakes++){
        int idx1 = lower_bound(iv.begin(), iv.end(), (2*N - E - 2*no_of_shakes)) - iv.begin();
        int idx2 = upper_bound(iv.begin(), iv.end(), (H - 3*no_of_shakes)) - iv.begin() - 1;
        
        cout << idx1 << " " << idx2 << endl;
        if(idx2 < idx1 || idx1 == N+1) continue;
        if(idx2 == N+1 && idx2 + 3*no_of_shakes > H) continue;
    
        int no_of_cakes;
        if(C > A) no_of_cakes = min(idx1, N - no_of_shakes);
        else no_of_cakes = min(idx2, N - no_of_shakes);
        
        int no_of_omelette = N - no_of_shakes - no_of_cakes;
        if(no_of_cakes + 2*no_of_shakes >= 2 * N - E && no_of_cakes + 3*no_of_shakes <= H){
            cout << no_of_omelette << " " << no_of_shakes << " " << no_of_cakes << endl;
            prices.push_back(A*no_of_omelette + B*no_of_shakes + C*no_of_cakes);
        }
    }

    if(!prices.empty()) ans = prices[0];
    for(int i = 1; i < prices.size(); i++) ans = min(ans, prices[i]);
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
    }
    return 0;
}