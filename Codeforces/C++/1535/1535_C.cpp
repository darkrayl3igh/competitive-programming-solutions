// https://codeforces.com/problemset/problem/1535/C
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
    string sequence; cin >> sequence;

    int n = sequence.size();
    vector<int> dp_0(n); 
    vector<int> dp_1(n);

    if(sequence[0] == '0') {
        dp_0[0] = 1;
    } else if(sequence[0] == '1') {
        dp_1[0] = 1;
    } else {
        dp_0[0] = 1;
        dp_1[0] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(sequence[i] != '0') {
            dp_1[i] = 1 + dp_0[i-1];
        }
        if(sequence[i] != '1') {
            dp_0[i] = 1 + dp_1[i-1];
        }
    }

    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += max(dp_0[i], dp_1[i]);
    }

    cout << answer << "\n";
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