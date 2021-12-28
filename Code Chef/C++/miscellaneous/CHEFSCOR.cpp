#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> series(3);
    int i=2,k=3;
    series[0]=1;
    series[1]=2;
    series[2]=2;
    int n=1000000000;
    while(n--)
    {
        for(int j=0;j<series[i];j++)
        {
            series.push_back(k);
        }
        i++;
        k++;
    }
    for(int i=0;i<200;i++)
    {
        cout<<series[i];
    }
    return 0;
}
