// https://codeforces.com/problemset/problem/1285/B
//Galatians 4:16

#include <bits/stdc++.h>

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define newline cout<<endl;
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

typedef long long int ll;

const double pi = 3.1415926535;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

long int max(long int a,long int b,long int c) { return max(max(a, b), c); }

long int maxCrossingSum(long int arr[], long int l, long int m, long int h)
{
    long int sum = 0;
    long int left_sum = INT_MIN;
    for (long int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    sum = 0;
    long int right_sum = INT_MIN;
    for (long int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return left_sum + right_sum;
}
long int maxSubArraySum(long int arr[], long int l, long int h)
{
   if (l == h)
     return arr[l];
   long int m = (l + h)/2;
   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}


int main()
{
    long int t,n,arr[100005]={0}, ans;
    cin>>t;
    while(t--)
    {
        long int sum=0;
        cin>>n;
        f(i,0,n) {cin>>arr[i]; sum+=arr[i];}
        ans=max(maxSubArraySum(arr, 0, n-2), maxSubArraySum(arr, 1, n-1));
        if(ans<sum) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}