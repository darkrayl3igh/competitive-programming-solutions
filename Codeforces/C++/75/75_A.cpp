// https://codeforces.com/problemset/problem/75/A
#include <iostream>
#include <cmath>

using namespace std;

int removeZeroes(int);
int a,b;

int main()
{
    cin>>a;
    cin>>b;
    if(removeZeroes(a)+removeZeroes(b)==removeZeroes(a+b)){cout<<"YES";}
    else{cout<<"NO";}

    return 0;
}

int removeZeroes(int x)
{
    int d=0;
    int i=0;
    while(x!=0)
    {
        if(x%10!=0)
        {
            d=d+((x%10)*pow(10,i));
            i++;
        }
        if(x!=0)
        {
            x=x/10;
        }
    }
    return d;
}