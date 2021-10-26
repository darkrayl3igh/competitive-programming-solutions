// https://codeforces.com/problemset/problem/1494/B
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
    int n, U, R, D, L, flag = 1; cin >> n >> U >> R >> D >> L;

    if(U == 0 && R == 0 && D == 0 && L == 0){
        cout << "YES\n"; return;
    }

    // U
    if(U > n-2 && R <= n-2 && D <= n-2 && L <= n-2)
    {
        int a = U - n + 2;
        if(a == 1){
            if(L < 1 && R < 1) flag = 0;
        }
        else if(a == 2){
            if(L < 1 || R < 1) flag = 0;
        }
    }
    // R
    if(U <= n-2 && R > n-2 && D <= n-2 && L <= n-2)
    {
        int a = R - n + 2;
        if(a == 1){
            if(U < 1 && D < 1) flag = 0;
        }
        else if(a == 2){
            if(D < 1 || D < 1) flag = 0;
        }
    }
    // D
    if(U <= n-2 && R <= n-2 && D > n-2 && L <= n-2)
    {
        int a = D - n + 2;
        if(a == 1){
            if(L < 1 && R < 1) flag = 0;
        }
        else if(a == 2){
            if(L < 1 || R < 1) flag = 0;
        }
    }
    // L
    if(U <= n-2 && R <= n-2 && D <= n-2 && L > n-2)
    {
        int a = L - n + 2;
        if(a == 1){
            if(U < 1 && D < 1) flag = 0;
        }
        else if(a == 2){
            if(D < 1 || D < 1) flag = 0;
        }
    }
    // U R
    if(U > n-2 && R > n-2 && D <= n-2 && L <= n-2)
    {
        int a = U - n + 2;
        int b = R - n + 2;

        if(a == 1 && b == 1){
            flag = 1;
        }
        if(a == 1 && b == 2){
            if(D < 1) flag = 0;
        }
        if(a == 2 && b == 1){
            if(L < 1) flag = 0;
        }
        if(a == 2 && b == 2){
            if(D < 1 || L < 1) flag = 0;
        }
    }
    // U D
    if(U > n-2 && R <= n-2 && D > n-2 && L <= n-2)
    {
        int a = U - n + 2;
        int b = D - n + 2;

        if(a == 1 && b == 1){
            if(L < 1 || R < 1) flag = 0;
        }
        if(a == 1 && b == 2){
            flag = 0;
        }
        if(a == 2 && b == 1){
            flag = 0;
        }
        if(a == 2 && b == 2){
            if(L < 2 || R < 2) flag = 0;
        }
    }
    // U L
    if(U > n-2 && R <= n-2 && D <= n-2 && L > n-2)
    {
        int a = U - n + 2;
        int b = L - n + 2;

        if(a == 1 && b == 1){
            flag = 1;
        }
        if(a == 1 && b == 2){
            if(D < 1) flag = 0;
        }
        if(a == 2 && b == 1){
            if(R < 1) flag = 0;
        }
        if(a == 2 && b == 2){
            if(D < 1 || R < 1) flag = 0;
        }
    }
    // R D
    if(U <= n-2 && R > n-2 && D > n-2 && L <= n-2)
    {
        int a = R - n + 2;
        int b = D - n + 2;

        if(a == 1 && b == 1){
            flag = 1;
        }
        if(a == 1 && b == 2){
            if(L < 1) flag = 0;
        }
        if(a == 2 && b == 1){
            if(U < 1) flag = 0;
        }
        if(a == 2 && b == 2){
            if(U < 1 || L < 1) flag = 0;
        }
    }
    // R L
    if(U <= n-2 && R > n-2 && D <= n-2 && L > n-2)
    {
        int a = R - n + 2;
        int b = L - n + 2;

        if(a == 1 && b == 1){
            if(U < 1 || D < 1) flag = 0;
        }
        if(a == 1 && b == 2){
            flag = 0;
        }
        if(a == 2 && b == 1){
            flag = 0;
        }
        if(a == 2 && b == 2){
            if(U < 2 || D < 2) flag = 0;
        }
    }
    // D L
    if(U <= n-2 && R <= n-2 && D > n-2 && L > n-2)
    {
        int a = D - n + 2;
        int b = L - n + 2;

        if(a == 1 && b == 1){
            flag = 1;
        }
        if(a == 1 && b == 2){
            if(U < 1) flag = 0;
        }
        if(a == 2 && b == 1){
            if(R < 1) flag = 0;
        }
        if(a == 2 && b == 2){
            if(U < 1 || R < 1) flag = 0;
        }
    }
    // U R D
    if(U > n-2 && R > n-2 && D > n-2 && L <= n-2)
    {
        int a = U - n + 2;
        int b = R - n + 2;
        int c = D - n + 2;

        if(a == 1 && b == 1 && c == 1){
            if(L < 1) flag = 0;
        }
        if(a == 1 && b == 1 && c == 2){
            if(L < 2) flag = 0;
        }
        if(a == 1 && b == 2 && c == 1){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 2){
            if(L < 1) flag = 0;
        }
        if(a == 2 && b == 1 && c == 1){
            if(L < 2) flag = 0;
        }
        if(a == 2 && b == 1 && c == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 1){
            if(L < 1) flag = 0;
        }
        if(a == 2 && b == 2 && c == 2){
            if(L < 2) flag = 0;
        }
    }
    // U R L
    if(U > n-2 && R > n-2 && D <= n-2 && L > n-2)
    {
        int a = R - n + 2;
        int b = U - n + 2;
        int c = L - n + 2;

        if(a == 1 && b == 1 && c == 1){
            if(D < 1) flag = 0;
        }
        if(a == 1 && b == 1 && c == 2){
            if(D < 2) flag = 0;
        }
        if(a == 1 && b == 2 && c == 1){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 2){
            if(D < 1) flag = 0;
        }
        if(a == 2 && b == 1 && c == 1){
            if(D < 2) flag = 0;
        }
        if(a == 2 && b == 1 && c == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 1){
            if(D < 1) flag = 0;
        }
        if(a == 2 && b == 2 && c == 2){
            if(D < 2) flag = 0;
        }
    }
    // U D L
    if(U > n-2 && R <= n-2 && D > n-2 && L > n-2)
    {
        int a = U - n + 2;
        int b = L - n + 2;
        int c = D - n + 2;

        if(a == 1 && b == 1 && c == 1){
            if(R < 1) flag = 0;
        }
        if(a == 1 && b == 1 && c == 2){
            if(R < 2) flag = 0;
        }
        if(a == 1 && b == 2 && c == 1){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 2){
            if(R < 1) flag = 0;
        }
        if(a == 2 && b == 1 && c == 1){
            if(R < 2) flag = 0;
        }
        if(a == 2 && b == 1 && c == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 1){
            if(R < 1) flag = 0;
        }
        if(a == 2 && b == 2 && c == 2){
            if(R < 2) flag = 0;
        }
    }
    // R D L
    if(U <= n-2 && R > n-2 && D > n-2 && L > n-2)
    {
        int a = R - n + 2;
        int b = D - n + 2;
        int c = L - n + 2;

        if(a == 1 && b == 1 && c == 1){
            if(U < 1) flag = 0;
        }
        if(a == 1 && b == 1 && c == 2){
            if(U < 2) flag = 0;
        }
        if(a == 1 && b == 2 && c == 1){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 2){
            if(U < 1) flag = 0;
        }
        if(a == 2 && b == 1 && c == 1){
            if(U < 2) flag = 0;
        }
        if(a == 2 && b == 1 && c == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 1){
            if(U < 1) flag = 0;
        }
        if(a == 2 && b == 2 && c == 2){
            if(U < 2) flag = 0;
        }
    }
    // U R D L
    if(U > n-2 && R > n-2 && D > n-2 && L > n-2)
    {
        int a = U - n + 2;
        int b = R - n + 2;
        int c = D - n + 2;
        int d = L - n + 2;

        if(a == 1 && b == 1 && c == 1 && d == 1){
            flag = 1;
        }
        if(a == 1 && b == 1 && c == 1 && d == 2){
            flag = 0;
        }
        if(a == 1 && b == 1 && c == 2 && d == 1){
            flag = 0;
        }
        if(a == 1 && b == 1 && c == 2 && d == 2){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 1 && d == 1){
            flag = 0;
        }
        if(a == 1 && b == 2 && c == 1 && d == 2){
            flag = 0;
        }
        if(a == 1 && b == 2 && c == 2 && d == 1){
            flag = 1;
        }
        if(a == 1 && b == 2 && c == 2 && d == 2){
            flag = 0;
        }
        if(a == 2 && b == 1 && c == 1 && d == 1){
            flag = 0;
        }
        if(a == 2 && b == 1 && c == 1 && d == 2){
            flag = 1;
        }
        if(a == 2 && b == 1 && c == 2 && d == 1){
            flag = 0;
        }
        if(a == 2 && b == 1 && c == 2 && d == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 1 && d == 1){
            flag = 1;
        }
        if(a == 2 && b == 2 && c == 1 && d == 2){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 2 && d == 1){
            flag = 0;
        }
        if(a == 2 && b == 2 && c == 2 && d == 2){
            flag = 1;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
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