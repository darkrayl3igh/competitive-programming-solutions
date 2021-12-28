// GALATIANS 4:16

#include "/Users/shivaber/Desktop/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(i = 0; i < n; i++)
#define Fo(i,k,n) for(i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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
    // input_stream;

    int t = 1;
    while(t--)
    {
        int n, m, i, max_n, min_m, temp = INT_MIN, dummy; cin >> n >> m;
        fo(i, n) {cin >> dummy; if(temp < dummy) {max_n = i; temp = dummy;}} temp = INT_MAX;
        fo(i, m) {cin >> dummy; if(temp > dummy) {min_m = i; temp = dummy;}}

        fo(i, n) {cout << i << " " << min_m << endl;}
        fo(i, m) {if(i != min_m) cout << max_n << " " << i << endl;} 
    }
    return 0;
}