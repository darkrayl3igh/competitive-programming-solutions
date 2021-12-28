// GALATIanswer 4:16

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
    int n; cin >> n;
    vector<vector<int> > lines(n);
    map<int, int> occ;

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int ant; cin >> ant;
            lines[i].pb(ant);
            occ[abs(ant)]++;
        }
    }

    ll answer = 0;

    for(auto ant: occ){
        if(ant.second > 1) answer++;
    }

    for(auto line: lines){
        vector<int> pos, neg;
        for(auto ant: line){
            if(ant < 0) neg.pb(ant);
            else pos.pb(ant);
        }

        reverse(all(pos));    

        while (true) {
            
            int closest;
            if (neg.empty() and pos.empty()) {
                break;
            } else if (neg.empty()) {
                closest = pos.back();
            } else if (pos.empty()) {
                closest = neg.back();
            } else {
                closest = (abs(neg.back()) < pos.back()) ? neg.back() : pos.back();
            }
            
            if (closest < 0) {
                if (occ[abs(closest)] > 1) {
                    answer += neg.size()-1;
                } else {
                    answer += pos.size();
                }
            } else {
                if (occ[abs(closest)] > 1) {
                    answer += pos.size()-1;
                } else {
                    answer += neg.size();
                }
            }
            
            if (closest < 0) {
                neg.pop_back();
            } else {
                pos.pop_back();
            }
        }
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


