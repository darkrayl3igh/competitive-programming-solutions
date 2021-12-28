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

void solve() {   
    ll n, m, K; cin >> n >> m >> K;
    double IP[n + 1][m + 1];
    
    for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < m+1; j++) {
            if (i == 0 || j == 0) {
                IP[i][j] = 0;
            } else {
                cin >> IP[i][j];
            }
        }
    }

    for(int i = 0; i < n+1; i++) {
        double temp = 0;
        for(int j = 0; j < m+1; j++) {
            IP[i][j] += temp;
            temp = IP[i][j];
        }
    }

    for(int i = 0; i < m+1; i++){
        double temp = 0;
        for(int j = 0; j < n+1; j++) {
            IP[j][i] += temp;
            temp = IP[j][i];
        }
    }
    
    ll z = min(n, m), answer = 0;
    for(int i = 1; i < z + 1; i++) {
        for(int j = i; j < n + 1; j++) {
            for(int k = i; k < m + 1; k++){
                if(((IP[j][k] + IP[j-i][k-i] - IP[j][k-i] - IP[j-i][k]) / (i*i)) >= K) {
                    answer++;
                }
            }
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