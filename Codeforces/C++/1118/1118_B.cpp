// https://codeforces.com/problemset/problem/1118/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,cnt=0,e=0,o=0,w;
    vector<int> candies;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        candies.push_back(a);
        if(i%2==0) e+=a;
        else o+=a;
    }
    w=o-e;
    if(w<0) w*=-1;
    for(int i=0;i<n;i++)
    {
        if(candies[i]==w) cnt++;
    }
    cout<<cnt;
    return 0;
}