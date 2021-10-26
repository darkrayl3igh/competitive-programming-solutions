// https://codeforces.com/problemset/problem/1538/G
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

bool check(ll cnt, ll x, ll y, ll a, ll b) {
    ll mn = (a*cnt-y+a-b-1)/(a-b);
    ll mx = (x-b*cnt)/(a-b);
    
    return (mn > cnt || mx < 0 || mn > mx) ? false : true;
}

void solve() {
    ll x, y, a, b; cin >> x >> y >> a >> b;
    
    ll low = 0;
    ll high = 1e9;
    ll answer = 0;
    
    if(x < y) {
        swap(x, y);
    }
    
    if(a < b) {
        swap(a, b);
    }
    
    if(a == b) {
        cout << min(x, y)/a << "\n";
        return;
    }
    
    while(low <= high) {
        ll mid = (low+high)/2;
        if(check(mid, x, y, a, b)) {
            answer = max(answer,mid);
            low = mid + 1;
        } else {
            high = mid - 1;
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