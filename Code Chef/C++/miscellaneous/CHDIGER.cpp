#include <bits/stdc++.h>

using namespace std;

unsigned long long int addD(unsigned long long int,int);
unsigned long long int removeI(unsigned long long int,int);

int main()
{
    unsigned long long int t,n,d,length=0,temp;
    cin>>t;
    while(t--)
    {
        vector<unsigned long long int> digits;
        length=0;
        cin>>n>>d;
        temp=n;
        while(temp>0)
        {
            temp/=10;length++;
        }
        temp=n;
        for(unsigned long long int i=0;i<length;i++)
        {
            digits.push_back(temp%10);
            temp/=10;
        }

        for(unsigned long long int i=digits.size()-1;i>=0;i--)
        {
            cout<<"a";
        }

        cout<<endl;
    }
}
