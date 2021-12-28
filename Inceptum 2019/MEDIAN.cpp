#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,M=-1,m=999,mi,Mi;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a>=M)
            {
                M=a; Mi=i;
            }
            if(a<=m)
            {
                m=a; mi=i;
            }
        }
        if(mi<Mi)
            cout<<m<<" "<<M<<endl;
        else
            cout<<M<<" "<<m<<endl;
    }
    return 0;
}
