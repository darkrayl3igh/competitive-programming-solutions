// https://codeforces.com/problemset/problem/1139/B
#include <bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

int main()
{
    int n,a,buy,i;
    unsigned long long int answer=0;
    vector<int> chocolates;
    cin>>n;
    f(i,0,n)
    {
        cin>>a;
        chocolates.pb(a);
    }
    buy=chocolates[n-1];
    i=n-1;
    while(buy>=0)
    {
        if(chocolates[i]>=buy)
        {
            answer+=buy;
            i-=1;
            buy-=1;
        }
        else
        {
            buy-=1;
        }
        if(i==-1)
        {
             break;
        }
    }
    cout<<answer;
    return 0;
}