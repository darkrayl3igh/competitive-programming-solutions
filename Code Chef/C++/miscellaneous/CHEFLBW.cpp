#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c,d,e;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d>>e;
        if(a==1&&b==0&&c==1&&d==1&&e==1) cout<<1;
        else cout<<0;
        cout<<endl;
    }
    return 0;
}
