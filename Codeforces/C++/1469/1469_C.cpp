// https://codeforces.com/problemset/problem/1469/C
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int t = 1; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> ground(n);
        for(int i = 0; i < n; i++) cin >> ground[i];

        int mx = ground[0], mn = ground[0];
        bool flag = true;
        for(int i = 1; i < n; i++){
            mn = max(mn - k + 1, ground[i]);
            mx = min(mx + k  - 1, ground[i] + k - 1);
            if(mn > mx){
                flag = false; break;
            }
        }

        if(ground[n - 1] > mx || ground[n - 1] < mn) flag = false;
        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}