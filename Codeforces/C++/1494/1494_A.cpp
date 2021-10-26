// https://codeforces.com/problemset/problem/1494/A
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
    string s; cin >> s;
    int n = s.size();
    if(s[0] == s[n-1]){
        cout << "NO\n";
        return;
    }

    int cnt_A = 0, cnt_B = 0, cnt_C = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') cnt_A++;
        else if(s[i] == 'B') cnt_B++;
        else if(s[i] == 'C') cnt_C++;
    }

    int counter = 0, flag = 1;

    if(cnt_A + cnt_B == cnt_C){
        if(s[0] == 'C'){
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter--;
                else if(s[i] == 'B') counter--;
                else if(s[i] == 'C') counter++;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter++;
                else if(s[i] == 'B') counter++;
                else if(s[i] == 'C') counter--;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
    }
    else if(cnt_A + cnt_C == cnt_B){
        if(s[0] == 'B'){
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter--;
                else if(s[i] == 'B') counter++;
                else if(s[i] == 'C') counter--;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter++;
                else if(s[i] == 'B') counter--;
                else if(s[i] == 'C') counter++;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
    }
    else if(cnt_B + cnt_C == cnt_A){
        if(s[0] == 'A'){
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter++;
                else if(s[i] == 'B') counter--;
                else if(s[i] == 'C') counter--;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(s[i] == 'A') counter--;
                else if(s[i] == 'B') counter++;
                else if(s[i] == 'C') counter++;

                if(counter < 0){
                    flag = 0;
                }
            }
        }
    }
    else{
        cout << "NO\n";
        return;
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