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
        int n, flag = 1, ans = 0; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sortall(arr);

        int lowest = n;
        for(int i = n - 1; i > -1; i--){
            if(arr[i] == i + 1) lowest = arr[i];
            if(arr[i] == arr[i - 1] && i != 0){
                if(arr[i] == lowest) flag = 0;
            }
        }

        if(!flag){
            cout << "Second\n";
            return;
        }

        for(int i = n - 1; i > -1; i--){
            if(arr[i] > i + 1) flag = 0;
            else ans += i + 1 - arr[i];
        }

        if(!flag){
            cout << "Second\n";
        }
        else{
            if(ans%2) cout << "First\n";
            else cout << "Second\n";
        }
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