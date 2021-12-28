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

int search(vector<int> arr, int val){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == val) return i;
    }
    return -1;
}
void solve(){
    int n, answer = 0; cin >> n;
    vector<int> w(n), l(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> l[i];

    map<int, int> track;
    for(int i = 1; i <= n; i++){
        track[i] = search(w, i);
    }

    for(int i = 2; i <= n; i++){
        int t1 = track[i];
        int t2 = track[i - 1];
        int temp = 0;
        if(t1 <= t2){
            temp = ceil((float(t2+1 - t1))/(float(l[t1])));
        }
        answer += temp;
        track[i] += temp*l[t1];
    }

    cout << answer << endl;
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