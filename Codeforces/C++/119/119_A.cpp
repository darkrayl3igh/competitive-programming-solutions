// https://codeforces.com/problemset/problem/119/A
#include <iostream>

using namespace std;

int a,b,n,c=0;

int gcd(int x,int y)
{
    for(int i=min(x,y);i>=1;i--)
    {
        if(x%i==0&&y%i==0)
        {
            return i;
        }
    }
}

int main()
{
    cin>>a>>b>>n;
    while(true)
    {
        c++;
        if(c%2==1)
        {
            n=n-gcd(a,n);
        }
        else
        {
            n=n-gcd(b,n);
        }
        if(n<=0){break;}
    }
    if(c%2==1){cout<<"0";}
    else{cout<<"1";}
    return 0;
}