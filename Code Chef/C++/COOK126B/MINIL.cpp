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

int compare(vector<vector<int> > current, vector<vector<int> > final){
    int row = current.size(), col = current[0].size(), answer = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(final[i][j] != current[i][j]) answer++;
        }
    }

    return answer;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int> > islands(n);
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        for(int j = 0; j < m; j++){
            if(temp[j] == '*') islands[i].pb(1);
            else islands[i].pb(0);
        }
    }

    if((n*m)%2){
        vector<vector<int> > final(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                final[i][j] = (i+j)%2 ? 0 : 1;
            }
        }
        cout << compare(islands, final) << endl;
    }
    else{
        vector<vector<int> > final1(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                final1[i][j] = (i+j)%2 ? 0 : 1;
            }
        }        
        
        vector<vector<int> > final2(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                final2[i][j] = (i+j)%2 ? 1 : 0;
            }
        }   
        
        cout << min(compare(islands, final1), compare(islands, final2)) << endl;
    }

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