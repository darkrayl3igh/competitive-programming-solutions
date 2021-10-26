// https://codeforces.com/problemset/problem/110/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int four=0,seven=0,n,temp;
    bool flag=false;

    cin>>n;

    seven=n/7;
    temp=n;

    while(true){
        if(seven<0){break;}
        temp-=(seven*7);
        if(temp%4==0)
        {
            four=temp/4;
            flag=true;
            break;
        }
        seven--;
        temp=n;
    }

    if(!flag){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<four;i++)
    {
        cout<<4;
    }
    for(int i=0;i<seven;i++)
    {
        cout<<7;
    }
    return 0;
}