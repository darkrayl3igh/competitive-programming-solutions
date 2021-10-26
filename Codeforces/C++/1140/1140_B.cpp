// https://codeforces.com/problemset/problem/1140/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,zeroes=0,ones=0;
        string s;

        cin>>n;
        cin>>s;

        if(s[0]=='>'||s[n-1]=='<'){cout<<0<<endl;continue;}
        int z=0;
        while(true)
        {
            if(s[z]=='<'){ zeroes++;z++;}
            else break;
        }
        int o=n-1;
        while(true)
        {
            if(s[o]=='>'){ ones++;o--;}
            else break;
        }
        cout<<min(ones,zeroes)<<endl;
    }
    return 0;
}