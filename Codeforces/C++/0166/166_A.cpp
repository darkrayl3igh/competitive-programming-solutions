// https://codeforces.com/problemset/problem/166/A
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;i++)
#define sonic() ios_base::sync_with_stdio(0)

using namespace std;

int main()
{
    sonic();
    vector< pair<int,int> > teams;
    pair<int,int> element;
    int n,k,a,b;

    cin>>n>>k;
    f(i,0,n)
    {
        cin>>a>>b;
        element.first=a;element.second=b;
        teams.push_back(element);
    }
    sort(teams.begin(),teams.end());
    f(i,0,n)
    {
        cout<<teams[i].first<<" "<<teams[i].second<<endl;
    }
    return 0;
}