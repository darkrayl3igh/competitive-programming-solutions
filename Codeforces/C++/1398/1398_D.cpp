// https://codeforces.com/problemset/problem/1398/D
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

vector<int> red(205), green(205), blue(205);
vector< vector< vector<int> > > dp(205, vector< vector<int> >(205, vector<int>(205, -1)));

void make_dp(int i,int j,int k)
{
    dp[i][j][k] = 0;
    if(i && j)
    {
        if(dp[i - 1][j - 1][k] == -1)
            make_dp(i - 1, j - 1, k);
        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + red[i] * green[j]);
    }
    if(i && k)
    {
        if(dp[i - 1][j][k - 1] == -1)
            make_dp(i - 1, j, k - 1); 
        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + red[i] * blue[k]);
    }
    if(j && k)
    {
        if(dp[i][j - 1][k - 1] == -1)
            make_dp(i, j - 1, k - 1); 
        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + green[j] * blue[k]);}
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int R, G, B; cin >> R >> G >> B;
    for(int i = 1; i <= R; i++) cin >> red[i];
    for(int i = 1; i <= G; i++) cin >> green[i];
    for(int i = 1; i <= B; i++) cin >> blue[i];

    sort(red.begin() + 1, red.begin() + R + 1); 
    sort(green.begin() + 1, green.begin() + G + 1); 
    sort(blue.begin() + 1, blue.begin() + B + 1); 
    
    make_dp(R, G, B);
    
    cout << dp[R][G][B];
    return 0;
}