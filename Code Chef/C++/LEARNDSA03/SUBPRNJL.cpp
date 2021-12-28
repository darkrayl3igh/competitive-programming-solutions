// GALATIANS 4:16

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
typedef tree< pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> oset;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

	int t; cin >> t;
	while(t--)
    {
	    int n, k; cin >> n >> k;
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            int count[2001] = {0};
            oset pdbs;
            for(int j = i; j < n; j++)
            {
                int size = j - i + 1, ptr, m, ind;
                m = (k % size == 0) ? k / size : k / size + 1;
                ind = (k % m == 0) ? k / m : k / m + 1; ind--;
                pdbs.insert(mp(arr[j], count[arr[j]]++));
                auto it = pdbs.find_by_order(ind);
                ptr = (*it).first;
                if(count[count[ptr]] > 0) answer++;
            }
        }
        cout << answer << endl;
	}
	return 0;
}