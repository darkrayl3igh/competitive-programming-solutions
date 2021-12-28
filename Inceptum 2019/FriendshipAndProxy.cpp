#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,m,a[100005],l,r,flag=0;
        cin>>k>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        k-=m;
        sort(a,a+n);
        l=0;
        r=n-1;
        while (l<r)
        {
            if (a[l]+a[r]==k)
            {
                flag=1;break;
            }
            else if (a[l]+a[r]<k)
                l++;
            else
                r--;
        }
        if(flag)
            cout<<"Ha\n";
        else
            cout<<"Na\n";
    }
    return 0;
}
