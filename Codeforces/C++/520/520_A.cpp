// https://codeforces.com/problemset/problem/520/A
#include <iostream>

using namespace std;

int n;
bool flag=true;
int alpha[26]={0};
string s;

int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(65<=s[i]&&90>=s[i])
        {
            alpha[s[i]-65]=1;
        }
        else
        {
            alpha[s[i]-97]=1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(alpha[i]==0){flag=false;break;}
    }
    if(flag){cout<<"YES";}
    else{cout<<"NO";}
    return 0;
}