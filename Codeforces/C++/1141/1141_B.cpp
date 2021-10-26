// https://codeforces.com/problemset/problem/1141/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,hour,start=0,ending=0,maxcounter=0,counter=0,flag=1;
    vector<int> day;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>hour;
        day.push_back(hour);
        if(flag==1&&hour==1)
        {
            start++;
        }
        else if(flag==1&&hour==0)
        {
            flag=0;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(day[i]==0) break;
        else ending++;
    }
    for(int i=0;i<n;i++)
    {
        if(day[i]==0) counter=0;
        else{counter++;}
        if(counter>maxcounter) maxcounter=counter;
    }
    cout<<max(maxcounter,start+ending);
    return 0;
}