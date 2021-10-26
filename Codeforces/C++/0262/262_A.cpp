// https://codeforces.com/problemset/problem/262/A
#include <iostream>

using namespace std;

int n,k,counter=0,c=0,a;

int main()
{
    cin>>n>>k;
    while(n--)
    {
        cin>>a;
        counter=0;
        while(true)
        {
            if(a%10==4||a%10==7||a==4||a==7)
            {
                counter++;
            }
            if(a==0)
            {
                break;
            }
            else
            {
                a=a/10;
            }
        }
        if(counter<=k){c++;}
    }
    cout<<c;
    return 0;
}