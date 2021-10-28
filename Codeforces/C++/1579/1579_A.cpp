// https://codeforces.com/problemset/problem/1579/A
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
    string s; cin >> s;
    if(s.size()%2) {
        cout << "NO\n";
        return;
    }
    int alpha[3]; memset(alpha, 0, sizeof(alpha));
    for(char& c: s) {
        alpha[c - 'A']++;
    }

    cout << ((alpha[1] == alpha[0] + alpha[2]) ? "YES\n" : "NO\n"); 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}