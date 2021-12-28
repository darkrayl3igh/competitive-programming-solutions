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

ll extract(ll num, ll digit) {
    ll idx = 0, final_idx = -1;
    while(num) {
        if(num%10 == digit) {
            final_idx = idx;
        }
        num /= 10;
        idx++;
    }
    return final_idx;
}

void solve() {
    ll n, d; cin >> n >> d;
    ll idx = extract(n, d), p_10 = pow(10, idx), closest, n_clone = n, idx_clone, answer;
    if(idx == -1) {
        cout << "0\n";
        return;
    } 

    while(idx != -1) {
        idx = extract(n_clone, d); 
        if(idx == -1) {
            break;
        }
        p_10 = pow(10, idx);
        n_clone = (n_clone/p_10)*p_10 + p_10;
    }

    cout << n_clone - n << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}