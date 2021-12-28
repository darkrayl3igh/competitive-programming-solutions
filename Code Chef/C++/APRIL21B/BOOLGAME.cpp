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
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> scores(N+1);
    for(int i = 0; i < N; i++) {
        cin >> scores[i+1];
    }

    vector<vector<pair<ll,ll> > > intervals(N+1);
    vector<vector<pair<ll,ll> > > tracker(N+1); tracker[0].pb(mp(0,0));
    
    for(int i = 0; i < M; i++) {
        ll U, V, D; cin >> U >> V >> D;
        intervals[U].pb(mp(i,D));
        intervals[V].pb(mp(i,D));
    }
    
    for(ll i = 1; i <= N; i++) {
        vector<pair<ll, ll> > bigboi; bigboi.insert(bigboi.end(), all(tracker[i-1]));
        
        ll curr = 0, M1 = 0;
        set<ll> setter;

        for(ll j = i; j >= 1; j--) {
            curr += scores[j];
            M1 ^= 1LL<<j;
            
            for(auto & [idx, val] : intervals[j]) {
                if(setter.count(idx)){
                    curr+=val;
                } else {
                    setter.insert(idx);
                }
            }
            
            if(j > 1) {
                for(auto & [val, M2] : tracker[j-2]) {
                    bigboi.pb(mp(val+curr, M1^M2));
                }
            } else {
                bigboi.pb(mp(curr, M1));
            }
        }
        sort(all(bigboi)); reverse(all(bigboi));
        
        set<ll> result;
        ll completed = 0;

        for(ll j = 0; j < bigboi.size() && completed < K; j++) {
            if(result.count(bigboi[j].S)) {
                continue;
            }
            
            tracker[i].pb(bigboi[j]);
            completed++;
            
            result.insert(bigboi[j].S);
        }
    }

    for(ll i = 0; i < K; i++) {
        cout << tracker[N][i].F << " ";
    }
    newline;
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