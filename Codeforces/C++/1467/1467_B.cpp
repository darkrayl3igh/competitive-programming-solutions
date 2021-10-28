// https://codeforces.com/problemset/problem/1467/B
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

const int N = 3e5;
int n, heights[N];

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

int isValley(int i) {
    return (i > 0 && i < n - 1 && heights[i] < heights[i - 1] && heights[i] < heights[i + 1]);
}

int isHill(int i) {
    return (i > 0 && i < n - 1 && heights[i] > heights[i - 1] && heights[i] > heights[i + 1]);
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    vector<int> is(n);
    int s = 0;
    for (int i = 1; i < n - 1; i++) {
        if (isHill(i) || isValley(i))
            is[i] = 1, s++;
    }

    int ans = s;
    for (int i = 1; i < n - 1; i++) {
        int temp = heights[i];
        heights[i] = heights[i - 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        heights[i] = heights[i + 1];
        ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
        heights[i] = temp;
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