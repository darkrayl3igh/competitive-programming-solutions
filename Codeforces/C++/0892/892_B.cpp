// https://codeforces.com/problemset/problem/892/B
#include <bits/stdc++.h>

using namespace std;

int n,counter=0,a;
vector<int> line;
vector<int> death;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        line.push_back(a);
        death.push_back(a);
    }
    for(int i=n-1;i>-1;i--)
    {
        for(int j=i-1;j>-1;j--)
        {
            if(j>=i-line[i]){death[j]=-1;}
        }
    }
    for(int i=0;i<n;i++)
    {
        if(death[i]!=-1){counter++;}
    }
    cout<<counter;
    return 0;
}