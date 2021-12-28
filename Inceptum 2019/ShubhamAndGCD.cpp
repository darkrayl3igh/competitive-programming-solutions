#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[505],b[505],s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            s+=__gcd(a[i],b[n-i+1]);
        cout<<s<<endl;
    }
    return 0;
}
