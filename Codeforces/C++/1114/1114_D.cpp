// https://codeforces.com/problemset/problem/1114/D
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,counter=0;
    vector<int> u(5000);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        u[a-1]=1;
    }
    for(int i=0;i<5000;i++)
    {
        if(u[i]==1){counter++;}
    }
    cout<<counter-1;
    return 0;
}