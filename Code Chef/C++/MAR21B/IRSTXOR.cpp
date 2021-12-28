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

string reverse(string num){
    string ret = "";
    for(int i = num.size()-1; i > -1; i--){
        ret += num[i];
    }
    return ret;
}

string d2b(int num){
    string ret = "";
    while(num > 0){
        ret += to_string(num%2);
        num /= 2;
    }
    return reverse(ret);
}

void solve(){   
    ll n, A = 0, B = 0; cin >> n;
    string C = d2b(n);
    
    int k = C.size() - 1;
    for(int i = 0; i < C.size(); i++){
        int two = pow(2, k);
        if(C[i] == '0'){
            A += two;
            B += two;
        }
        else{
            if(abs(A + two - B) < abs(B + two - A)){
               A += two; 
            }
            else{
                B += two;
            }
        }
        k--;
    }

    cout << A * B << "\n";
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