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
#define debug_2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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

bool compare(pii a, pii b){
    return a.F < b.F;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    vector<pii> points;
    vector<int> L(300000, -1), R(300000, -1);
    stack<int> st;

    points.push_back({0, 0});
    points.push_back({100000, 0});
    
    for(int i = 1;i < 100000; i++)
        points.push_back({i, 500});

    int n, x, y, ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    sort(points.begin(), points.end(), compare);


    for(int i = 0; i < points.size(); i++)
    {
        while(!st.empty())
        {
            if(points[st.top()].S < points[i].S) {L[i] = points[st.top()].F; break;}
            else st.pop();
        }
        st.push(i);
    };

    while(!st.empty()) st.pop();

    for(int i = points.size() - 1; i >= 0; i--){
        
        while(!st.empty())
        {
            if(points[st.top()].S < points[i].S) {R[i] = points[st.top()].F; break;}
            else st.pop();
        }
        st.push(i);
    }  

    for(int i = 0; i < points.size(); i++)
    {
        int y = points[i].S;
        if(L[i] == -1 || R[i] == -1) continue;
        ans = max(ans, (R[i] - L[i]) * y);
    }
    cout << ans << endl;

    return 0;
}