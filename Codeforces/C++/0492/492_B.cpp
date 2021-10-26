// https://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long double lantern,l;
    long double lanternDiameter;
    vector<long double> street;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        cin>>lantern;
        street.push_back(lantern);
    }
    sort(street.begin(),street.end());

    lanternDiameter=0;

    for(int i=0;i<n-1;i++)
    {
        if(street[i+1]-street[i]>lanternDiameter) lanternDiameter=street[i+1]-street[i];
    }
    lanternDiameter/=2.0;
    lanternDiameter=max(street[0]-0,max(lanternDiameter,l-street[n-1]));
    cout<<lanternDiameter;
    return 0;
}