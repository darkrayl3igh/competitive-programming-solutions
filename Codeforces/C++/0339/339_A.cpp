// https://codeforces.com/problemset/problem/339/A
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
    int one = 0, two = 0, three = 0, plus = 0;
    for(char& c: s) {
        one += (c == '1');
        two += (c == '2');
        three += (c == '3');
        plus += (c == '+');
    }
    string ans = "";
    while(one--) {
        ans += "1";
        if(plus) {
            ans += "+";
            plus--;
        }
    }
    while(two--) {
        ans += "2";
        if(plus) {
            ans += "+";
            plus--;
        }
    }
    while(three--) {
        ans += "3";
        if(plus) {
            ans += "+";
            plus--;
        }
    }

    cout << ans << endl;
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