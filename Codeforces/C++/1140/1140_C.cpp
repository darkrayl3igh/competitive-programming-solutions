// https://codeforces.com/problemset/problem/1140/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<pair<int,int> > spotify;
    pair<int,int> song;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>song.first>>song.second;
        spotify.push_back(song);
    }
    sort(spotify.begin(),spotify.end());
    for(int i=0;i<n;i++)
    {
        cout<<spotify[i].first<<" "<<spotify[i].second<<endl;
    }
    return 0;
}