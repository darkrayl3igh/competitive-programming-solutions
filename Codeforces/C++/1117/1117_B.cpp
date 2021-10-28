// https://codeforces.com/problemset/problem/1117/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int n,m,k,a,m1,m2;
    vector<int> emotes;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        emotes.push_back(a);
    }
    sort(emotes.begin(),emotes.end());
    m1=emotes[n-1];m2=emotes[n-2];

    cout<<( ((k*m1)+m2)*(m/(k+1)) ) + m1*(m%(k+1));
    return 0;
}