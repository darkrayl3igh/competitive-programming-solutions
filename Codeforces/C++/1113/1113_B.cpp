// https://codeforces.com/problemset/problem/1113/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,aj,sum,real=0,sub;
    vector<int> magnets;

    cin>>n;

    while(n--)
    {
        cin>>a;
        magnets.push_back(a);
        real+=a;
    }

    sort(magnets.begin(),magnets.end());

    aj=magnets[0];
    sum=real;
    for(int i=magnets.size()-1;i>0;i--)
    {
        vector<int> factors;
        for(int j=1;j<=magnets[i]/2;j++)
        {
            if(magnets[i]%j==0)
            {
                factors.push_back(j);
            }
        }
        sort(factors.rbegin(),factors.rend());
        for(int k=factors.size()-1;k>=0;k--)
        {
            if(sum>real+(aj*factors[k])+(magnets[i]/factors[k])-aj-magnets[i])
            {
                sum=real+(aj*factors[k])+(magnets[i]/factors[k])-aj-magnets[i];
                sub=magnets[i];
            }
        }
    }
    cout<<min(real,sum);
    return 0;
}