// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define Fo(i,k,n) for(int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define debug(x) cout << #x << "=" << x << endl
#define debug_2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input_stream;

    int t = 1; cin >> t;
    while(t--)
    {
        int n, l; cin >> n;
        bool flag = true;
        vector<int> splits;
        int counter, max_val = -1;
        fo(i, n)
        {
            int temp; cin >> temp;
            if(temp == 0 && flag)
            {
                flag = false; l = i;
            }
            if(temp == 1 && !flag)
            {
                flag = true; splits.pb(i - l);
            }
        }
        sort(splits.begin(), splits.end());
        int m = splits.size();
        if(m == 0) {cout << "No\n"; continue;}
        if(m > 1)
        {
            int a = splits[m - 1], b = splits[m - 2];
            if(a == b) {cout << "No\n"; continue;}
            if(a % 2 == 0) {cout << "No\n"; continue;}
            else
            {
                if(ceil(a / 2.0) > b) cout << "Yes\n";
                else cout << "No\n";
            }
        }
        else
        {
            if(splits[0] % 2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}