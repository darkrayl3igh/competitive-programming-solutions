// https://codeforces.com/problemset/problem/1538/A
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
    int n; cin >> n;
    int mn = INT_MAX, mx = INT_MIN;
    int idx_mx = -1, idx_mn = -1;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp > mx) {
            mx = temp;
            idx_mx = i;
        }

        if(temp < mn) {
            mn = temp;
            idx_mn = i;
        }
    }

    int A = min(idx_mn, idx_mx);    
    int B = max(idx_mn, idx_mx);    

    cout << min(n-A, min(B+1, (A+1 + n-B))) << "\n";
    
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