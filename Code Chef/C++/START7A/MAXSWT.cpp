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

struct compare {
    bool operator()(const pair<ll, ll>& candy_one, const pair<ll, ll>& candy_two) const {
        return candy_one.second == candy_two.second ? candy_one.first < candy_two.first : candy_two.second < candy_one.second;
    }
};

void solve(){
    int n, d; cin >> n >> d;
    vector<pair<ll, ll> > candies(n);
    
    for(int i = 0; i < n; i++) {
        cin >> candies[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> candies[i].second;
    }

    sortall(candies);
    multiset<pair<ll, ll>, compare> tracker;
    ll answer = 0;
    ll l = 0;
    for(int r = n-1; r >= 0; r--) {
        while(l < r && candies[l].first + candies[r].first <= d) {
            tracker.insert(candies[l]);
            l++;
        }

        auto itr = tracker.find(candies[r]);
        if(l > r && itr != tracker.end()) {
            tracker.erase(itr);
        }

        if(!tracker.empty()) {
            if(tracker.begin()->first + candies[r].first <= d) {
                answer = max(answer, tracker.begin()->second + candies[r].second);
            }
        } else {
            if(candies[r].first <= d) {
                answer = max(answer, candies[r].second);
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