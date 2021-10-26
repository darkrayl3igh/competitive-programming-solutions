// https://codeforces.com/problemset/problem/337/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,f[1000]={0};
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>f[i];
    }
    //for(int i=0;i<m;i++){cout<<f[i]<<endl;}
    sort(f,f+m);
    //for(int i=0;i<m;i++){cout<<f[i]<<endl;}
    int mind=INT_MAX;
    for(int i=0;i<m-n+1;i++)
    {
        if(f[n+i-1]-f[i]<mind)
        {
            mind=f[n+i-1]-f[i];
        }
    }
    cout<<mind;
    return 0;
}