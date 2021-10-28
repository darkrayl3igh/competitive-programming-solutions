// https://codeforces.com/problemset/problem/1114/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,d,g,m,p;
    cin>>a>>d>>m;
    cin>>g>>p>>b;
    if(g>=a)
    {
        g-=a;
        if(g+p>=d)
        {
            p-=d;
            if(g+p+b>=m)
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}