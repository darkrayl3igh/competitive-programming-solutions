// https://codeforces.com/problemset/problem/344/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,counter=0;
    string a,b="22";
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a!=b){counter++;}
        b=a;
    }
    cout<<counter;
    return 0;
}