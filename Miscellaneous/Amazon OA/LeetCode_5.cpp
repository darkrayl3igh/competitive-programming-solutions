// https://leetcode.com/discuss/interview-question/1474282/Amazon-OA
// GALATIANS 4:16

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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
    string str, ans = ""; cin >> str;
    int k; cin >> k;

    k %= 26;
    k = 26-k;
    for(int i = 0; i < str.size(); i++) {
        ans += 'A' + (str[i] - 'A' + k)%26;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}