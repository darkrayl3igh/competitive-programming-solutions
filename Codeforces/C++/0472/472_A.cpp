// https://codeforces.com/problemset/problem/472/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> primes(1000005);
    int n,a,b;

    for(int i=2;i<=1000005;i++)
    {
        if(primes[i]==0)
        {
            for(int j=2;i*j<=1000005;j++)
            {
                primes[i*j]=1;
            }
        }
    }
    cin>>n;
    a=n-4;
    b=4;
    while(true)
    {
        if(primes[a]&&primes[b])
        {
            cout<<b<<" "<<a;
            return 0;
        }
        else{a--;b++;}
    }
}