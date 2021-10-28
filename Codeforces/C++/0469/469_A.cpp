// https://codeforces.com/problemset/problem/469/A
#include <iostream>

using namespace std;

int main()
{
    int n,p,q,d,e;
    cin>>n;
    int a[n+2]={0};
    cin>>p;
    while(p--)
    {
        cin>>d;
        a[d-1]=1;
    }
    cin>>q;
    while(q--)
    {
        cin>>e;
        a[e-1]=1;
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<"I become the guy.";
    }
    else
    {
        cout<<"Oh, my keyboard!";
    }
    return 0;
}