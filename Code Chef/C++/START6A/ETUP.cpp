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
    int N, Q; cin >> N >> Q;
    vector<int> arr(N+1);

    for(int i = 1; i <= N; i++) {
        int temp; cin >> temp;
        arr[i] = temp % 2;
        
        if(i > 1) {
            arr[i] += arr[i-1];
        }
    }

    while(Q--) {
        int L, R; cin >> L >> R;
        int odd = arr[R] - arr[L-1];
        int even = R-L+1 - odd;

        ll answer = 0;
        if(odd > 1) {
            ll add = odd;
            add *= (odd-1);
            add /= 2;
            add *= even;
            answer += add;
        }
        if(even > 2) {
            ll add = even;
            add *= (even-1);
            add *= (even-2);
            add /= 6;
            answer += add;
        }
        
        cout << answer << "\n";
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