#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,a,p=0,n=0,low,high;
        vector<int> series,groups;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a;
            if(a>0) p++;
            if(a<0) n++;
        }
        low=min(p,n);
        high=max(p,n);
        if(n==0||p==0) cout<<high<<" "<<high<<endl;
        else cout<<high<<" "<<low<<endl;
    }
    return 0;
}
