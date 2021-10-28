// https://codeforces.com/problemset/problem/1141/D
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=0;
    string firstString,secondString;
    cin>>n;
    cin>>firstString;
    cin>>secondString;
    vector<int> firstAlpha(26);
    vector<int> secondAlpha(26);
    vector<char> boots;
    for(int i=0;i<n;i++)
    {
        firstAlpha[firstString[i]-'a']+=1;
        secondAlpha[secondString[i]-'a']+=1;
        if(firstString[i]=='?') ans++;
        if(secondString[i]=='?') ans++;
    }
    for(int i=0;i<26;i++)
    {
        ans+=min(firstAlpha[i],secondAlpha[i]);
        for(int j=0;j<min(firstAlpha[i],secondAlpha[i]);j++)
        {
            boots.push_back('a'+i);
        }
    }
    if(ans>n) cout<<n<<endl;
    else cout<<ans<<endl;
    for(int i=0;i<boots.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            if(firstString[j]==boots[i]){ cout<<j+1<<" ";firstString[j]='0';break;}
        }
        for(int j=0;j<n;j++)
        {
            if(secondString[j]==boots[i]){ cout<<j+1<<endl;secondString[j]='0';break;}
        }
    }
    for(int i=0;i<n;i++)
    {
        if(firstString[i]=='?')
        {
            for(int j=0;j<n;j++)
            {
                if(secondString[j]!='0')
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    firstString[i]='0';secondString[j]='0';break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(secondString[i]=='?')
        {
            for(int j=0;j<n;j++)
            {
                if(firstString[j]!='0')
                {
                    cout<<j+1<<" "<<i+1<<endl;
                    firstString[j]='0';secondString[i]='0';break;
                }
            }
        }
    }
    return 0;
}