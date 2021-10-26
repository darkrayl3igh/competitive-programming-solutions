// https://codeforces.com/problemset/problem/61/A
#include <iostream>

using namespace std;

string a,b;

int main()
{
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i]){cout<<0;}
        else{cout<<1;}
    }
    return 0;
}