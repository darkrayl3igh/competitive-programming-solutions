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
    ll n; cin >> n;
    ll twos = (n/4)*4, threes = 0, fours = 0, fives = 0;
    int decider = n%4;
    
    if(twos == 0) {
        if(decider == 0) {
            twos = 0;
        } else if(decider == 1) {
            fives = 1;
        } else if(decider == 2) {
            fours = 2;
        } else if(decider == 3) {
            threes = 1;
            fours = 2;
        }
    }
    else {
        if(decider == 0) {
            twos -= 4;
            threes = 4;
        } else if(decider == 1) {
            twos -= 3;
            threes = 3;
            fives = 1;
        } else if(decider == 2) {
            twos -= 2;
            threes = 2;
            fours = 2;
        } else if(decider == 3) {
            twos -= 1;
            threes = 2;
            fours = 2;
        }
    }
    cout << twos*11 + threes*15 + fours*18 + fives*20 << "\n";
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