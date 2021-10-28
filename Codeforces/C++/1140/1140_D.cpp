// https://codeforces.com/problemset/problem/1140/D
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long int answer=0;
    cin>>n;
    for(int i=2;i<n;i++)
    {
        answer+=i*(i+1);
    }
    cout<<answer;
    return 0;
}