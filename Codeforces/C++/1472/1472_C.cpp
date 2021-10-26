// https://codeforces.com/problemset/problem/1472/C
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
        int A[n+1];
        for(int i = 1; i <= n; i++) cin >> A[i];
        vector<int> vect(n+1);
    
        int ans = 0;
    
        vect[n] = A[n]; 
        for(int i = n-1; i >= 1; i--){
            if(A[i]+i > n) vect[i] = A[i];
            else vect[i] = A[i] + vect[i + A[i]];
        }
        for(int i=1;i<=n;i++) ans=max(ans,vect[i]);
        cout << ans << endl;
    }
    return 0;
}