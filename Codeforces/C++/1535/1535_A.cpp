// https://codeforces.com/problemset/problem/1535/A
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
    vector<int> arr(4);
    int mx_1 = -1, idx_1 = -1;
    int mx_2 = -1, idx_2 = -1;
    
    for(int i = 0; i < 4; i++) {
        cin >> arr[i];
        if(arr[i] > mx_1) {
            mx_1 = arr[i];
            idx_1 = i;
        }
    }

    for(int i = 0; i < 4; i++) {
        if(arr[i] != mx_1) {
            if(arr[i] > mx_2) {
                mx_2 = arr[i];
                idx_2 = i;
            }
        }
    }

    if((idx_1 < 2 && idx_2 < 2) || (idx_1 > 1 && idx_2 > 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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