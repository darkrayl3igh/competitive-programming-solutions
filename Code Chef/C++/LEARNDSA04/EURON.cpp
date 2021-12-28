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
#define newine cout << endl
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

vector<int> arr(100005);
ll counter = 0;

vector<int> merge_vectors(vector<int> left, vector<int> right)
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j]) {merged.pb(left[i]); i++;}
        else
        {
            merged.pb(right[j]); j++;
            counter += left.size() - i;
        }
    }
    while (i < left.size()) {merged.pb(left[i]); i++;}
    while (j < right.size()) {merged.pb(right[j]); j++;}
    return merged;
}

void merge_sort(int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(l, mid); merge_sort(mid + 1, r);
        vector<int> left, right;
        for(int i = l; i <= mid; i++) left.pb(arr[i]);
        for(int i = mid + 1; i <= r; i++) right.pb(arr[i]);
        vector<int> temp = merge_vectors(left, right);
        for(int i = 0; i < temp.size(); i++) arr[l + i] = temp[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n - 1);
    cout << counter << endl;
    return 0;
}