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

vector<int> answer(1000006);
 
void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
 
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for(int i = 2; i < answer.size(); i++){
        if(prime[i] && prime[i - 2]){
            answer[i] = answer[i - 1] + 1;
        }
        else answer[i] = answer[i - 1];
    }
}

void solve(){
    int n; cin >> n;
    cout << answer[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    SieveOfEratosthenes(1000005);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}