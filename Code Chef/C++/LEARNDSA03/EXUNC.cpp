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

    int n, queries, elem, value, type;
    cin >> n >> queries; 
    string query;
    set<int> splits;
    vector<int> elements(n + 1); elements[0] = 1;

    for(int i = 1; i <= n; i++) cin >> elements[i]; 
    
    splits.insert(1);
    
    for(int i = 2; i <= n; i++)
    {
        if(elements[i] % elements[i - 1])
            splits.insert(i);
    }

    // for(auto ptr = splits.begin(); ptr != splits.end(); ptr++)
    //     cout << *ptr << " ";
    newline;
    for(int i = 0; i < queries; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> elem >> value;
            elements[elem] = value;
            auto ptr = splits.upper_bound(elem); ptr--;
            splits.insert(elem);
            splits.insert(elem + 1);
            if(elem > 1)
                {if(!(elements[elem] % elements[elem - 1])) splits.erase(splits.lower_bound(elem));}
            if(elem < n)
                {if(!(elements[elem + 1] % elements[elem])) splits.erase(splits.lower_bound(elem + 1));}
        }
        else
        {
            cin >> elem;
            auto ptr = splits.begin();
            ptr = splits.upper_bound(elem); ptr--;
            cout << *ptr << endl;
        }
    }
    return 0;
}