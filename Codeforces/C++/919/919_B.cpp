// https://codeforces.com/problemset/problem/919/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,sum,i=1,tempi;
    cin>>k;
    while(k>0)
    {
        sum=0;tempi=i;
        while(tempi>0)
        {
            sum+=tempi%10;tempi/=10;
        }
        if(sum==10) k--;
        i++;
    }
    cout<<i-1;
    return 0;
}