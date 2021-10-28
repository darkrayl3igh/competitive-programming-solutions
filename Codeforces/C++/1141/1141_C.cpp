// https://codeforces.com/problemset/problem/1141/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,maxDiff=0,x,flag=1;
    vector<int> differences(1);
    vector<int> permutation;
    vector<int> checker(200001);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        differences.push_back(differences[i-1]+a);
        if(differences[i]>maxDiff) maxDiff=differences[i];
    }
    x=n-maxDiff;
    for(int i=0;i<n;i++)
    {
        permutation.push_back(x+differences[i]);
        checker[x+differences[i]-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(checker[i]==0){ flag=0;break;}
    }
    if(flag)
    {
        for(int i=0;i<n;i++) cout<<permutation[i]<<" ";
    }
    else cout<<-1;
    return 0;
}