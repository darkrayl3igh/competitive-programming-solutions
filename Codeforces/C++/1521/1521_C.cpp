// https://codeforces.com/problemset/problem/1521/C
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

int query(int t, int i, int j, int x){
    cout << "? " << t << " " << i << " " << j << " " << x << "\n";
    cout.flush();
    int ret; cin >> ret;
    return ret;
}
 
int helper(int n){
    for(int i = 1;i < n; i += 2) {
        int ret = query(1, i, i+1, n-1);
        if(ret == n) {
            return i+1;
        } else if(ret == n-1) {
            int ret = query(1, i+1, i, n-1);
            if(ret == n) {
                return i;
            }
        }
    }
    return n;
}

void solve(){
    int n; cin >> n;
    int arr[n+1];
    int idx = helper(n);
    
    arr[idx] = n;
    for(int i = 1; i <= n; i++) {
        if(i != idx) {
        arr[i] = query(2, i, idx, 1);
        }
    }

    cout << "! ";
    for(int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
    }
    newline;

    cout.flush();
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