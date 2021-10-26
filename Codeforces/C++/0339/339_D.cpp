// https://codeforces.com/problemset/problem/339/D
// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
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
int N;

int calculateDistance(int pos){
    int ans = 0;
    while(pos < N){
        pos = 2*pos+1;
        ans++;
    }

    return ans;
}

void updateSegmentTree(int segTree[], int pos, int val){
    segTree[pos] = val;
    while(pos){
        int distance = calculateDistance(pos);
        distance--;
        if(distance != 0 && distance%2 == 1){
            segTree[pos] = segTree[2*pos+1] | segTree[2*pos+2];
        }
        else if (distance != 0 && distance%2 == 0){
            segTree[pos] = segTree[2*pos+1] ^ segTree[2*pos+2];
        }  
        pos = (pos - 1)/2;      
    }

    int distance = calculateDistance(0);
    distance--;
    if(distance != 0 && distance%2 == 1){
        segTree[0] = segTree[1] | segTree[2];
    }
    else if (distance != 0 && distance%2 == 0){
        segTree[0] = segTree[1] ^ segTree[2];
    }
}


void constructSegmentTree(int arr[], int segTree[], int low, int high, int pos){
    if(low == high){
        segTree[pos] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    constructSegmentTree(arr, segTree, low, mid, 2*pos + 1);
    constructSegmentTree(arr, segTree, mid+1, high, 2*pos + 2);
    
    int distance = calculateDistance(pos);
    distance--;
    if(distance != 0 && distance%2 == 1){
        segTree[pos] = segTree[2*pos+1] | segTree[2*pos+2];
    }
    else if (distance != 0 && distance%2 == 0){
        segTree[pos] = segTree[2*pos+1] ^ segTree[2*pos+2];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    n = pow(2, n);
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    N = n * 2; N--;
    int segTree[N];
    constructSegmentTree(arr, segTree, 0, n-1, 0);

    while(m--){
        int pos, val; cin >> pos >> val;
        pos--;
        pos += N - n;
        updateSegmentTree(segTree, pos, val);
        cout << segTree[0] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}