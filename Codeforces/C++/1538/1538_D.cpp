// https://codeforces.com/problemset/problem/1538/D
// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << \nx
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << endl;
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1e9+7;

ll gcd (ll a, ll b){return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp){
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if(exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

const int N = 50000;

vector<bool> isPrime(N, true);
vector<int> primes;

void precalc() {
    for(int i = 2; i*i < N; i++) {
        for(int j = i*i; j < N; j += i) {
            isPrime[j] = false;
        }
    }

    for(int i = 2; i < N; i++) {
        if(isPrime[i]) {
            primes.pb(i);
        }
    }
}
 
int count_prime(int n) {
    int count = 0;
    for(int i = 0; i < 4203 && n > 1; i++) {
        while(n%primes[i] == 0) {
            count++; 
            n /= primes[i];
        }
    }

    if(n > 1) {
        count++;
    }

    return count;
}
 
void solve()
{
    int a, b, k; cin >> a >> b >> k;
    int total = count_prime(a)+count_prime(b);
    if(total<k) {
        cout << "NO\n";
    } else {
        if(k == 1) {
            if((a%b==0 || b%a==0) && (a != b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "YES\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    precalc();
    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}