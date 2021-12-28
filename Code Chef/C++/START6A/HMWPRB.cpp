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
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == k) {
        cout << "0\n";
        return;
    }

    vector<int> dp(n);
    deque<pair<int, int> > tracker;

    for(int i = 0; i <= k; i++) {
        dp[i] = arr[i];
        while(!tracker.empty() && tracker.back().first > dp[i]) {
            tracker.pop_back();
        }
        tracker.push_back(mp(dp[i], i));
    }

    for(int i = k+1; i < n; i++) {
        while(!tracker.empty() && tracker.front().second < i - k - 1) {
            tracker.pop_front();
        }
        dp[i] = arr[i] + tracker.front().first;
        while(!tracker.empty() && tracker.back().first > dp[i]) {
            tracker.pop_back();
        }
        tracker.push_back(mp(dp[i], i));
    }

    int ans = INT_MAX;
    for(int i = n-k-1; i < n; i++) {
        ans = min(ans, dp[i]);
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
    }

    return 0;
}