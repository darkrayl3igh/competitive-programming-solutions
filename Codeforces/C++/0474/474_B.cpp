// https://codeforces.com/problemset/problem/474/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,m;
    vector<int> worms;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++) worms.push_back(i);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        cout<<worms[a-1]<<endl;
    }
    return 0;
}