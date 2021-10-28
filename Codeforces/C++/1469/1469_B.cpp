// https://codeforces.com/problemset/problem/1469/B
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
        int n; cin >> n;
        vector<int> prefix_n(n + 1);
        
        for(int i = 1; i <= n; i++){
            cin >> prefix_n[i];
            prefix_n[i] = prefix_n[i] + prefix_n[i - 1];
        }

        int m; cin >> m;
        vector<int> prefix_m(m + 1);
        
        for(int i = 1; i <= m; i++){
            cin >> prefix_m[i];
            prefix_m[i] = prefix_m[i] + prefix_m[i - 1];
        }

        cout << *max_element(all(prefix_n)) + *max_element(all(prefix_m)) << endl;
    }
    return 0;
}