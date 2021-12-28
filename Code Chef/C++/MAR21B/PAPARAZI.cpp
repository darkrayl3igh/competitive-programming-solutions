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

double slope(pair<int, int> A, pair<int, int> B){
	return (double) ((double) A.second - (double) B.second) / ((double) A.first - (double) B.first);
}

void solve(){   
    int n, ans = 1; cin >> n;
    vector<pair<int, int> > points(n), temp_vec;
    for(int i = 0; i < n ; i++){
        int temp; cin >> temp;
        points[i] = mp(i + 1, temp);
    }

    if(n == 2){
        cout << ans << "\n";
        return;
    }

    temp_vec.pb(points[0]);
    temp_vec.pb(points[1]);

    int curr = temp_vec.size();

    for(int i = 2; i < n; i++){
        while(temp_vec.size() >= 2){
            double slope_A = slope(temp_vec[curr - 1], temp_vec[curr - 2]);
            double slope_B = slope(points[i], temp_vec[curr - 1]);
            if (slope_A <= slope_B){
                temp_vec.pop_back();
                curr--;
            } 
            else break;
        }
        temp_vec.pb(points[i]);
        curr++;
        int height_A = temp_vec[curr - 1].first;
        int height_B = temp_vec[curr - 2].first;
        ans = max(ans, height_A - height_B);
    }
    cout << ans << "\n";
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

