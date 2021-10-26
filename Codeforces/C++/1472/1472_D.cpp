// https://codeforces.com/problemset/problem/1472/D
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
        int n; cin >> n;
        multiset<int, greater<int> > odd, even;
        ll alice = 0, bob = 0;

        for(int i = 0; i < n; i++){
            int val; cin >> val;
            if(val%2) odd.insert(val);
            else even.insert(val);   
        }
        
        int turn = 0;
        while(!(odd.empty()) && !(even.empty())){
            if(turn%2 == 0){
                if(*(odd.begin()) > *(even.begin())){
                    odd.erase(odd.begin());
                }
                else{
                    alice += *(even.begin());
                    even.erase(even.begin());
                }
            }
            else{
                if(*(even.begin()) > *(odd.begin())){
                    even.erase(even.begin());
                }
                else{
                    bob += *(odd.begin());
                    odd.erase(odd.begin());
                }
            }

            turn++;
        }


        while(!(odd.empty())){
            if(turn%2 == 1){
                bob += *(odd.begin());
            }
            odd.erase(odd.begin());
            turn++;
        }    
        while(!(even.empty())){
            if(turn%2 == 0){
                alice += *(even.begin());
            }
            even.erase(even.begin());
            turn++;
        }  

        if(alice > bob) cout << "Alice\n";
        else if(bob > alice) cout << "Bob\n";
        else cout << "Tie\n";
    }
    return 0;
}