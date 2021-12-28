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
    int n,q,m;
    cin >> n >> q >> m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int b[1000001] = {};
    int ans[m + 1] = {};
    map<pair<int, int>, int> m1;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (a[l] > m) continue;
        else if (a[l] <= m && a[r] > m) b[a[l]]++, b[m + 1]--;
        else if (a[r] <= m) {
            b[a[l]]++, b[m + 1]--;
            m1[{a[l], a[r]}]++;
        }
    }
    for (auto x : m1) {
        int k = x.F.F, p = x.F.S, l = x.S;
        b[p + k] -= l, b[p + 2 * k] += l;
        int c = p + 2 * k;
        while(c + p <= m) {
            c += p;
            b[c] -= l, b[c + k] += l;
            c += k;
        }
    }
    for(int i = 1; i <= m; i++) b[i] += b[i - 1];
    
    
    int mx = 0;
    for (int i = 0; i <= m; i++) mx = max(b[i], mx);
    cout << mx << "\n";
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