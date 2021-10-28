// https://codeforces.com/problemset/problem/1139/A
#include <bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int main()
{
    string s;
    int answer=0,n;
    cin>>n;
    cin>>s;
    f(i,0,n)
    {
        if(s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='8')
        {
            answer+=1;answer+=i;
        }
    }
    cout<<answer;
    return 0;
}