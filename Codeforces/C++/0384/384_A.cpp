// https://codeforces.com/problemset/problem/384/A
#include <iostream>

using namespace std;

int n,counter;
string s[1005]={""};

int main()
{
    cin>>n;
    if(n%2==0)
    {
        cout<<n*n/2<<endl;
    }
    else
    {
        cout<<((((n+2)*(n+2))+((n-2)*(n-2)))/4)-1<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(n%2==0&&i%2==0)
            {
                if(j%2==0){s[i]+="C";}
                else{s[i]+=".";}
            }
            else if(n%2==0&&i%2==1)
            {
                if(j%2==0){s[i]+=".";}
                else{s[i]+="C";}
            }
            else if(n%2==1&&i%2==0)
            {
                if(j%2==0){s[i]+="C";}
                else{s[i]+=".";}
            }
            else if(n%2==1&&i%2==1)
            {
                if(j%2==0){s[i]+=".";}
                else{s[i]+="C";}
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}