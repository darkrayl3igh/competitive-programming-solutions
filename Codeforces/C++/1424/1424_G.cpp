// https://codeforces.com/problemset/problem/1424/G
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

    long long int n, counter, answer;
    cin >> n;
    vector<pair<int, int> > input_data(n);
    set<long long int> unique_years;
    for(int i = 0; i < n; i++)
    {
        cin >> input_data[i].F >> input_data[i].S;
        unique_years.insert(input_data[i].F);   
        unique_years.insert(input_data[i].S);   
    }

    counter = unique_years.size();
    
    vector<long long int> copy, final(counter);
    for(auto x : unique_years) copy.pb(x);

    for(int i = 0; i < n; i++)
    {
        long long int birth, death, index;
        birth = input_data[i].F; death = input_data[i].S;
        index = lower_bound(all(copy), birth) - copy.begin(); final[index]++;
        index = lower_bound(all(copy), death) - copy.begin(); final[index]--;
    }

    for(int i = 1; i < counter; i++) final[i] += final[i - 1];

    answer = *max_element(all(final));
    for(int i = 0; i < counter; i++)
    {
        if(final[i] == answer)
        {
            cout << copy[i] << " " << answer << "\n";
            break;
        }
    }
    return 0;
}