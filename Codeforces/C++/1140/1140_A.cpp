// https://codeforces.com/problemset/problem/1140/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int answer=0,n,mystery,maxMystery;
    vector<int> pages(1);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>mystery;
        pages.push_back(mystery);
    }
    maxMystery=0;
    for(int i=1;i<=n;i++)
    {
        if(pages[i]>maxMystery) maxMystery=pages[i];
        if(i==maxMystery) answer++;
    }
    cout<<answer;
    return 0;
}