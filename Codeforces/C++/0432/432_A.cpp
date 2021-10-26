// https://codeforces.com/problemset/problem/432/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,n0=0,n1=0,n2=0,n3=0,n4=0,a;
    cin>>n>>k;
    while(n--)
    {
        cin>>a;
        switch(a)
        {
            case 0: n0++;break;
            case 1: n1++;break;
            case 2: n2++;break;
            case 3: n3++;break;
            case 4: n4++;break;
        }
    }
    switch(k)
    {
        case 1: cout<<(n0+n1+n2+n3+n4)/3;break;
        case 2: cout<<(n0+n1+n2+n3)/3;break;
        case 3: cout<<(n0+n1+n2)/3;break;
        case 4: cout<<(n0+n1)/3;break;
        case 5: cout<<(n0)/3;break;
    }
    return 0;
}