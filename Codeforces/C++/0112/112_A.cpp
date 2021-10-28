// https://codeforces.com/problemset/problem/112/A
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
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) {
        char c1 = s1[i], c2 = s2[i];
        if('A' <= c1 && c1 <= 'Z') {
            c1 += 'a' - 'A';
        }
        if('A' <= c2 && c2 <= 'Z') {
            c2 += 'a' - 'A';
        }
        if(c1 > c2) {
            cout << 1; return;
        } else if(c2 > c1) {
            cout << -1; return;
        }
    }

    cout << 0;
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