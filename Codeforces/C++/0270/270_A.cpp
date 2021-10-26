// https://codeforces.com/problemset/problem/270/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int intn;
    float n,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        n=360/(180-a);
        intn=(int)n;
        if(intn==n)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}