#include <bits/stdc++.h>
#define ll long long int
#define F(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define NL "\n"
#define dd double
#define __ ' '
#define mp make_pair
#define fi first
#define se second
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define ull unsigned int long long
const int INF = INT_MAX;
#define INFL LLONG_MAX
#define f_scan ios_base::sync_with_stdio(!cin.tie(0))
#define all(x) x.begin(), x.end()
#define mod 998244353
#define debug(x) cout << #x << " " << x << endl;
#define deci(n) fixed << setprecision(n)
using namespace std;

 
int32_t main()
{
    f_scan;
    
    tc{
        int n;
        cin>>n;
        int arr[n];
        int arr1[n];
        F(i,0,n){
            cin>>arr[i];
            arr1[i]=arr[i];
        }
        sort(arr1,arr1+n);
        vector<pair<pair<int,int>,int>>v;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(arr[i]==arr1[i]){
                    break;
                }
                if(arr1[i]==arr[j]){
                     v.pb({{j+1,i+1},1});
                        rotate(arr,j,n);
                }
            }
        }
        cout<<v.size()<<NL;
        for(auto k:v){
            cout<<k.fi.fi<<__<<k.fi.se<<__<<k.se<<NL;
        }
    }
    
    return 0;
}
