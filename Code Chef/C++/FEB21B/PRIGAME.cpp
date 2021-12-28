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

vector<ll> primes;

void sieveBuilder(int n)
{
    vector<bool> sieve(n, true);
 
    for (int p = 2; p * p <= n; p++)
        if (sieve[p]) 
            for (int i = p * p; i <= n; i += p)
                sieve[i] = false;
 
    for (int p = 2; p <= n; p++)
        if (sieve[p])
            primes.pb(p);
}

void solve(){   
    int x, y; cin >> x >> y;
    int ind = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    if(y < ind){
        cout << "Divyam\n";
    }
    else{
        cout << "Chef\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    sieveBuilder(15485900);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}