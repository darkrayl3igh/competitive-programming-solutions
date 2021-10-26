// https://codeforces.com/problemset/problem/758/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,richest=-1,sum=0;
    vector<int> people;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        people.push_back(a);
        if(a>richest) richest=a;
    }
    for(int i=0;i<n;i++)
    {
        sum+=(richest-people[i]);
    }
    cout<<sum;
    return 0;
}