// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(k) cout << #k << "=" << k << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(k) k.begin(), k.end()
#define sortall(k) sort(all(k))
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1e9+7;

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

void flip(char *x){
	if(*x == '1') {
        *x = '0';
    } else {
        *x = '1';
    }
}

void solve(){
    int N, M, E; cin >> N >> M >> E;
    vector <pair<char, vector<int> > > ans;
    char A[N + 1][M + 1], B[N + 1][M + 1];

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= M; j++){
            if(i == 0 || j == 0) A[i][j] = 0;
            else cin >> A[i][j];
        }
    }

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= M; j++){
            if(i == 0 || j == 0) B[i][j] = 0;
            else cin >> B[i][j];
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if(B[i][j] != '?' && A[i][j] != B[i][j]){
                bool flag = false;

                for (int k = 0; k <= M; k++){
                    if(k != j){
                        if(B[i][k] != '?' && A[i][k] != B[i][k]){
                            flag = true;
                            vector<int> temp; temp.pb(i); temp.pb(j); temp.pb(k);
                            ans.pb(mp('R', temp));
                            A[i][j] = B[i][j];
                            A[i][k] = B[i][k];
                            break;
                        }
                    }
                }

                if(!flag){
                    for (int k = 0; k <= N; k++){
                        if(k != i){
                            if(B[k][j] != '?' && A[k][j] != B[k][j]){
                                flag = true;
                                vector<int> temp; temp.pb(j); temp.pb(i); temp.pb(k);
                                ans.pb(mp('C', temp));
                                A[i][j] = B[i][j];
                                A[k][j] = B[k][j];
                                break;
                            }
                        }
                    }
                }

                if(!flag){
                    for (int k = 0; k <= M; k++){
                        if(B[i][k] == '?'){
                            flag = true;
                            vector<int> temp; temp.pb(i); temp.pb(j); temp.pb(k);
                            ans.pb(mp('R', temp));
                            A[i][j] = B[i][j];
                            flip(&A[i][k]);
                            break;
                        }
                    }
                }

                if(!flag){
                    for (int k = 0; k <= N; k++){
                        if(B[k][j] == '?'){
                            flag = true;
                            vector<int> temp; temp.pb(j); temp.pb(i); temp.pb(k);
                            ans.pb(mp('C', temp));
                            A[i][j] = B[i][j];
                            flip(&A[k][j]);
                            break;
                        }
                    }
                }
            }
        }
    }

    bool flag_2 = true;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if(B[i][j] != '?' && A[i][j] != B[i][j]){
                flag_2 = false; break;
            }
        }
    }
    if(flag_2 == false) {
        cout << "-1\n";
    } else {
        cout << ans.size() << "\n";
        if(E == 1){
            for (auto ptr1: ans){
                cout << ptr1.first << " ";
                for (auto ptr2: ptr1.second){
                    cout << ptr2 << " ";
                }
                newline;
            }
        }
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