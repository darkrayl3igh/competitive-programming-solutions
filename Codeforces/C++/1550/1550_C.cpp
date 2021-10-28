// https://codeforces.com/problemset/problem/1550/C
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

int helper(int A, int B, int C) {
    if (A >= B && B >= C) {
        return 0;
    } else if (A <= B && B <= C) {
        return 0;
    }

    return 1;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = 2*n - 1;
    for(int i = 0; i < n-2; i++) {
        answer += helper(arr[i], arr[i+1], arr[i+2]);
    }

    for(int i = 0; i < n-3; i++) {
        if(helper(arr[i], arr[i+1], arr[i+2]) && helper(arr[i], arr[i+1], arr[i+3]) && helper(arr[i], arr[i+2], arr[i+3]) && helper(arr[i+1], arr[i+2], arr[i+3])) {
            answer++;
        }
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