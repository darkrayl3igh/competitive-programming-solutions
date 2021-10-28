// https://codeforces.com/problemset/problem/1469/D
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

void div(int num, vector<pair<int, int> >& answer){
    if(num == 2) return;
    int part = 2;

    while(part < ceil(num/part)){
        part++;
    }

    for(int i = part+1; i < num; i++){
        answer.pb({i, num});
    }
    answer.pb({num, part});
    answer.pb({num, part});
    div(part, answer);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int t = 1; cin >> t;
    while(t--){
        vector<pair<int, int> > answer;
        int n; cin >> n;
        div(n, answer);
        cout << answer.size() << endl;
        for(auto it = answer.begin(); it != answer.end(); it++){
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}