// https://codeforces.com/problemset/problem/69/A
// GALATIANS 4:16

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << "\n"
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1e9+7;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}
int random(int x, int y) {return (rand() % (y-x)) + x;}

void solve() {
    int forces, x_total = 0, y_total = 0, z_total = 0; cin >> forces;
    for(int i = 0; i < forces; i++) {
        int x, y, z; cin >> x >> y >> z;
        x_total += x;
        y_total += y;
        z_total += z;
    }

    cout << (x_total == 0 && y_total == 0 && z_total == 0 ? "YES" : "NO");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}