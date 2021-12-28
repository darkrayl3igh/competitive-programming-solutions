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

int search_distinct(string A, string B){
    set<char> counter;
    for(int i = 0; i < A.size(); i++) counter.insert(A[i]);
    for(int i = 0; i < B.size(); i++) counter.insert(B[i]);
    return counter.size();
}

void solve(){   
    int n, answer = 0; cin >> n;
    vector<string> names(n), keys;
    for(int i = 0; i < n; i++) cin >> names[i];
    map<string, string> track;

    for(int i = 0; i < n; i++){
        string temp = names[i].substr(1, names[i].size() - 1);
        if(track.find(temp) != track.end()){
            track[temp] = track[temp] + names[i][0];
        }
        else{
            track[temp] = names[i][0];
        }
    }

    for(auto it = track.begin(); it != track.end(); it++) keys.push_back(it->F);
    for(int i = 0; i < track.size(); i++){
        for(int j = i + 1; j < track.size(); j++){
            int temp = search_distinct(track[keys[i]], track[keys[j]]);
            answer += (temp - track[keys[i]].size()) * (temp - track[keys[j]].size());
        }
    }

    cout << 2 * answer << endl;

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