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

int gcd (int a, int b) {return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((int)result * base) % MOD;
      base = ((int)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

vector<int> process_one, process_two;

bool isinrange(int a, int b) {
    for(int i = 0;i < process_one.size(); i++){
        if(process_one[i] <= b && process_two[i] >= a){
            return true;
        }
    }
    return false;
}

void solve(){   
    int n, m, x, y; cin >> n >> m >> x >> y;
    int A[m], B[m], C[m], D[m];
    
    for(int i = 0; i < m; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    if(x == y){
        cout << "0\n";
        return;
    }

    int di[m], ans = -1, z = 0;
    
    for(int i = 0; i < m; i++) {
        di[i] = 0;
    }
    
    vector<int> vec_one, vec_two;
    vec_one.push_back(x);
    vec_two.push_back(x);
    
    while((ans == -1) && (vec_one.size() != 0)){
        process_one.clear(); process_two.clear();
        process_one = vec_one; process_two = vec_two;
        vector<int> temp_one, temp_two;
        for(int i = 0; i < m; i++) {
            if((di[i] == 0) && isinrange(A[i], B[i])) {
                temp_one.push_back(C[i]);
                temp_two.push_back(D[i]);
                if(C[i] <= y && D[i] >= y) {
                    ans = z+1;
                }
                di[i] = 1;
            }
        }
        vec_one = temp_one;
        vec_two = temp_two;
        z++;
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