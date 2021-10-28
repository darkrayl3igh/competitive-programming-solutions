// https://codeforces.com/problemset/problem/1472/B
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
        int one = 0, two = 0;
        
        for(int i = 0; i < n; i++){
            int w; cin >> w;
            if(w == 1) one++;
            else two++;
        }

        if(n == 1){
            cout << "NO\n";
            continue;
        }
        int sum = one + 2*two;
        if(sum%2 == 1){
            cout << "NO\n";
            continue;
        }
        if(one == two){
            cout << "YES\n";
            continue;
        }
        if(one == 0){
            if(two%2) cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        if(two == 0){
            if(one%2) cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        if(two%2 == 0 && one%2 == 0){
            cout << "YES\n";
            continue;
        }
        cout << "YES\n";

    }
    return 0;
}