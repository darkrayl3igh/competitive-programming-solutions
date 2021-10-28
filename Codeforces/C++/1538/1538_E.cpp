// https://codeforces.com/problemset/problem/1538/E
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

const int MOD = 1e9+7;

ll gcd (ll a, ll b){return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp){
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

string find_pre(string str) {
    string answer;

    for(int j = 0; j < min(3, (int)str.size()); j++) {
        answer += str[j];
    }
    
    return answer;
}

string find_suf(string str) {
    string answer;
    int sz = str.size();

    for(int j = max(0, sz-3); j < sz; j++) {
        answer += str[j];
    }
    
    return answer;
}

ll find_cnt(string str) {
    ll answer = 0;
    
    for(int j = 0; j+3 < str.size(); j++) {
        if(str[j] == 'h' && str[j+1] == 'a' && str[j+2] == 'h' && str[j+3] == 'a') {
            answer++;
        }
    }

    return answer;
}

void solve() {
    int n; cin >> n;
    ll answer = 0LL;
    
    map<string,string> prefix;
    map<string,string> suffix;
    map<string,ll> counter;

    for(int i = 0; i < n; i++) {
        string variable, operation; cin >> variable >> operation;
        
        if(operation == ":=") {
            string value; cin >> value;
            prefix[variable] = find_pre(value);
            suffix[variable] = find_suf(value);
            counter[variable] = find_cnt(value);
            answer = counter[variable];
        } else {
            string variable_1, sign, variable_2; cin >> variable_1 >> sign >> variable_2;
            counter[variable] = counter[variable_1] + counter[variable_2] + find_cnt(suffix[variable_1]+prefix[variable_2]);
            prefix[variable] = find_pre(prefix[variable_1]+prefix[variable_2]);
            suffix[variable] = find_suf(suffix[variable_1]+suffix[variable_2]);
            answer = counter[variable];

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