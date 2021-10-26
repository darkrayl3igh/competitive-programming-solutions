// https://codeforces.com/problemset/problem/1420/A
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


ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) 
{ 
    ll inv_count = 0; 
  
    ll i = left; 
    ll j = mid;  
    ll k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
    return inv_count; 
} 
ll _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) 
    { 
        mid = (right + left)/2; 
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
  
    return inv_count; 
} 
  
ll countSwaps(ll arr[], ll n) 
{ 
    ll temp[n]; 
    return _mergeSort(arr, temp, 0, n - 1); 
} 
  
int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;
    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++) cin >> arr[i];

        ll ans = countSwaps(arr, n);
        ll check = (n * (n - 1)) / 2 - 1;
        if(ans <= check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0; 
}