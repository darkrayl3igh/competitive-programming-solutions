// https://codeforces.com/problemset/problem/278/A
#include <iostream>

using namespace std;

int n,pathOne,pathTwo,totalDistance,s,t;
int d[103]={0};

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        totalDistance+=d[i];
    }
    cin>>s>>t;
    for(int i=min(s,t);i<max(t,s);i++)
    {
        pathOne+=d[i-1];
    }
    pathTwo=totalDistance-pathOne;
    cout<<min(pathOne,pathTwo);
    return 0;
}