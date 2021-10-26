// https://codeforces.com/problemset/problem/1141/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,m,counter=0;
    cin>>n>>m;
    if(m%n!=0){ cout<<-1; return 0;}
    m/=n;
    while(m%2==0)
    {
        counter++;
        m/=2;
    }
    while(m%3==0)
    {
        counter++;
        m/=3;
    }
    if(m!=1){ cout<<-1; return 0;}
    else{ cout<<counter;}
    return 0;
}