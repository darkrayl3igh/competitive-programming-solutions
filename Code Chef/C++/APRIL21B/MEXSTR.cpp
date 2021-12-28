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
const int MX = (int)1e6;

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

int dp[MX + 2], DP[MX + 2];
int upcoming_0[MX], upcoming_1[MX];

void solve() {
    string s, answer = "1"; cin >> s;
    int n = s.size(), last_pos;

    last_pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            for (int j = last_pos + 1; j <= i; j++) {
                upcoming_0[j] = i;
            }
            last_pos = i;
        }
    }

    for (int i = last_pos + 1; i < n; i++) {
        upcoming_0[i] = n;
    }

    if (upcoming_0[0] == n) {
        cout << "0\n";
        return;
    }

    last_pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = last_pos + 1; j <= i; ++j) {
                upcoming_1[j] = i;
            }
            last_pos = i;
        }
    }

    for (int i = last_pos + 1; i < n; i++) {
        upcoming_1[i] = n;
    }

    dp[n] = dp[n + 1] = 0;
    DP[n] = DP[n + 1] = 0;

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        if (s[i] == '0' && upcoming_1[i] < n) {
            dp[i] = max(dp[i], dp[upcoming_1[i]+1] + 1);
        }
        if (s[i] == '1' && upcoming_0[i] < n) {
            dp[i] = max(dp[i], dp[upcoming_0[i]+1] + 1);
        }
        DP[i] = DP[i + 1];
        if (upcoming_1[i] < n) {
            DP[i] = max(DP[i], dp[upcoming_1[i]+1] + 1);
        }
    }

    int N = DP[0] + 1;
    int curr = upcoming_1[0] + 1;
    
    for (int i = 1; i < N; i++) {
        if (curr >= n) {
            answer.push_back('0');
            continue;
        }
        if (upcoming_0[curr] >= n) {
            answer.push_back('0');
            curr = upcoming_0[curr] + 1;
            continue;
        }
        if (dp[upcoming_0[curr] + 1] < N - i - 1) {
            answer.push_back('0');
            curr = upcoming_0[curr] + 1;
        } else {
            answer.push_back('1');
            curr = upcoming_1[curr] + 1;
        }
    }

    cout << answer << '\n';
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


