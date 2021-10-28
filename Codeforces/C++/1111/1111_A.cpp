// https://codeforces.com/problemset/problem/1111/A
#include <bits/stdc++.h>
#define pb(elem) push_back(elem)
#define sonic() ios::sync_with_stdio(false)


using namespace std;

int isVowel(char);

int main()
{
    sonic();
    string s,t;
    bool flag=true;
    cin>>s>>t;
    if(s.size()!=t.size()){cout<<"No";return 0;}

    for(int i=0;i<s.size();i++)
    {
        if(isVowel(s[i])!=isVowel(t[i])){flag=false;break;}
    }
    if(flag){cout<<"Yes";}
    else{cout<<"No";}
    return 0;
}

int isVowel(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){return 5;}
    else{return 6;}
}