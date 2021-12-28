#include <bits/stdc++.h>
#define ll long long int
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int nCrModpDP(int n, int r, int p)
{
	int C[r+1];
	memset(C, 0, sizeof(C));

	C[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = min(i, r); j > 0; j--)

			C[j] = (C[j] + C[j-1])%p;
	}
	return C[r];
}

int nCrModpLucas(int n, int r, int p)
{
if (r==0)
	return 1;
int ni = n%p, ri = r%p;

return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;
}
int main()
{
    ll t,a,b,c,isum=0,jsum=0,cons=0;
    cin>>t;
    while(t--)
    {
        isum=0;
        cin>>a>>b>>c;
        for(int i=2;i<=a;i++)
        {
            jsum=0;
            for(int j=1;j<i;j++)
            {
                jsum+=nCrModpLucas(b,j,1000000007);
            }
            isum+=jsum*nCrModpLucas(a,i,1000000007);
        }
        cons=power(2,c,1000000007);
        cons-=1;
        cout<<(cons*isum)%1000000007;
        cout<<endl;
    }
    return 0;
}
