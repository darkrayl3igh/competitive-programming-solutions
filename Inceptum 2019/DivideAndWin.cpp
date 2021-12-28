#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[105],n,flag=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            if(abs(a[i+1]-a[i])==1)
            {
                flag=1;break;
            }
        }
        if(flag)
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
