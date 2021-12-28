// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define F(i,s,e) for(long long int i=s;i<=e;i++)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

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

ll dp[4020][4020];
ll pref[4020];

ll recurse(ll idx,ll choice,ll n,ll k,vector<ll> &arr){
    if(choice>=k and (pref[idx]-choice>=k)) return 0;
    else if(idx>=n)  return 1e10;
    else if(dp[idx][choice]!=-1) return dp[idx][choice];

    ll step1 = recurse(idx+1,min(choice+arr[idx],pref[idx]-choice),n,k,arr);
    ll step2 = recurse(idx+1,min(pref[idx]-choice+arr[idx],choice),n,k,arr);
    
    return dp[idx][choice] = 1+min(step1,step2);
}

ll builddp(vector<ll> &arr,ll n,ll k){
    f(i,0,n/2) swap(arr[i],arr[n-i-1]);
    F(i,0,n+10){
        pref[i]=0;
        F(j,0,k+10) dp[i][j]=-1;
    }
    F(i,1,n) pref[i]=pref[i-1]+arr[i-1];
    ll ans = recurse(0,0,n,k,arr);
    return ans>1e9?-1:ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr        
    }
    sort(all(arr));
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    cout<<builddp(arr,n,k)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}