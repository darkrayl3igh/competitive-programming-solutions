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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int t = 1; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        ll john_sum = 0, jack_sum = 0;
        vector<int> john(n), jack(m);
        for(int i = 0; i < n; i++){
            cin >> john[i];
            john_sum += john[i];
        }
        for(int i = 0; i < m; i++){
            cin >> jack[i];
            jack_sum += jack[i];
        }

        sort(john.begin(), john.end(), greater<int>());
        sortall(jack);

        bool flag = false;

        ll answer = 0, john_ptr = john.size() - 1, jack_ptr = jack.size() - 1;
        while(john_sum <= jack_sum){
            if(john_ptr < 0 || jack_ptr < 0){
                flag = true;
                break;
            }
            john_sum -= john[john_ptr];
            john_sum += jack[jack_ptr];

            jack_sum -= jack[jack_ptr];
            jack_sum += john[john_ptr];

            int temp = john[john_ptr];
            john[john_ptr] = jack[jack_ptr];
            jack[jack_ptr] = temp;
            answer++;
            john_ptr--; jack_ptr--;
        }
        if(flag) cout << -1 << endl;
        else cout << answer << endl;
    }
    return 0;
}