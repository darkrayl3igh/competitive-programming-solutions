#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a,ans=1;
    vector<int> bats;
    cin>>n;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a;
        if(a>n)
        {
            cout<<-1;
            return 0;
        }
        bats.push_back(a);
    }
    int r=0,sum=0;
    while(r<k)
    {
        if(bats[r]+sum<n)
        {
            sum+=bats[r];
            r++;
        }
        else if(bats[r]+sum>n)
        {
            sum=0;
            ans++;
        }
        else if(bats[r]+sum==n)
        {
            sum=0;
            r++;
            ans++;
        }
    }
    if(bats[k-1]==n) ans--;
    cout<<ans<<endl;
    return 0;
}
