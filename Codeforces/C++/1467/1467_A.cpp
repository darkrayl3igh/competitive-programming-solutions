// https://codeforces.com/problemset/problem/1467/A
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
    int n; cin >> n;
    if(n == 1){
        cout << 9 << endl;
        return;
    }
    if(n == 2){
        cout << 98 << endl;
        return;
    }
    if(n == 3){
        cout << 989 << endl;
        return;
    }
    vector<ll> digits(3);
    digits[0] = 9;
    digits[1] = 8;
    digits[2] = 9;
    
    int counter = 0;
    n -= 3;
    while(n--){
        digits.pb(counter);
        counter++;
        if(counter == 10) counter = 0;
    }
    for(int i = 0; i < digits.size(); i++){
        cout << digits[i];
    }
    newline;
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