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
     vector<int>v(n);
     F(i,0,n){
         cin>>v[i];
     }
     deque<int>dq;
     dq.push_back(v[0]);
     F(i,1,n){
         if(v[i]<dq.front()){
             dq.push_front(v[i]);
         }
         else{
             dq.push_back(v[i]);
         }
     }
     while(!dq.empty()){
         cout<<dq.front()<<__;
         dq.pop_front();
     }
     cout<<NL;
    }
    
    return 0;
}
