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
    // input_stream;

    int t = 1; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> splits;
        multiset<int, greater<int> > count;

        splits.pb(0);
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] != s[i + 1])
            {
                splits.pb(i + 1);
            }
        }
        splits.pb(n);

        for(int i = 0; i < splits.size() - 1; i++)
        {
            if(s[0] - '0' && i % 2)
                count.insert(splits[i + 1] - splits[i]);
            if(!(s[0] - '0') && !(i % 2))
                count.insert(splits[i + 1] - splits[i]);
        }

        int search_val1 = -1, search_val2 = -1;
        
        if(s[0] == '0') search_val1 = splits[1] - splits[0];      
        if(s[n - 1] == '0') search_val2 = splits[splits.size() - 1] - splits[splits.size() - 2];      
        
        int answer = 0;

        for(auto ptr = count.begin(); ptr != count.end(); ptr++)
        {
            if(k > 1)
            {
                if(*ptr == search_val1) 
                {
                    k -= 1;
                    search_val1 = -1;
                }
                else if(*ptr == search_val2)
                {
                    k -= 1;
                    search_val2 = -1;
                }
                else k -= 2;
            }
            else if(k == 1)
            {
                if(*ptr == search_val1) 
                {
                    k -= 1;
                    search_val1 = -1;
                }
                else if(*ptr == search_val2)
                {
                    k -= 1;
                    search_val2 = -1;
                }
                else answer += *ptr;
            }
            else
            {
                answer += *ptr;
            }
        }

        cout << answer << endl;

    }
    return 0;
}