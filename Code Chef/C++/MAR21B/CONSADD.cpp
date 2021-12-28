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
    int rows, cols, val; cin >> rows >> cols >> val;
    int A[rows][cols], B[rows][cols], C[rows][cols];

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            cin >> B[i][j];
        }
    }
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            C[i][j] = B[i][j] - A[i][j];
        }
    }


    for(int j = 0; j < cols;j++){
        int diff = 0;
        int k = rows - val;
        while(k >= 0){
            diff += C[k][j];
            k -= val;
        }
        for(int i = rows-1; i > rows-val;i--){
            int temp = i - val;
            while(temp >= 0){
                C[i][j] += C[temp][j];
                temp = temp - val;
            }
            C[i][j] -= diff;
        }
    }

    for(int i = rows-1;i > rows-val; i--){
        int diff = 0;
        int k = cols - val;
        while(k >= 0){
            diff += C[i][k];
            k -= val;
        }
        for(int j = cols-1; j > cols-val; j--){
            int temp = j - val;
            while(temp >= 0){
                C[i][j] += C[i][temp];
                temp = temp-val;
            }
            C[i][j] -= diff;
        }
    }

    bool flag = true;
    for(int i = rows-1; i > rows-val;i --){
        for(int j = cols-1; j > cols-val; j--){
            if(C[i][j]!=0) flag = false;
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";

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