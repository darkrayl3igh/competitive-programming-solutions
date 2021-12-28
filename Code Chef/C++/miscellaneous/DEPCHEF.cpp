#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;i++)
#define m(a,b,c) min(a,min(b,c))
using namespace std;

int main()
{
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> attack(n);
        vector<int> defense(n);
        vector<int> survivor(n);
        f(i,0,n)
            cin>>attack[i];
        f(i,0,n)
            cin>>defense[i];
        f(i,1,n-1)
        {
            if(m(defense[i]-attack[i+1]-attack[i-1],defense[i]-attack[i+1],defense[i]-attack[i-1])>0)
                survivor[i]=1;
        }
        if(m(defense[0]-attack[1]-attack[n-1],defense[0]-attack[1],defense[0]-attack[n-1])>0)
            survivor[0]=1;
        if(m(defense[n-1]-attack[n-2]-attack[0],defense[n-1]-attack[n-2],defense[n-1]-attack[0])>0)
            survivor[n-1]=1;
        ans=-1;
        f(i,0,n)
        {
            if(survivor[i]==1)
                if(defense[i]>ans)
                    ans=defense[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
