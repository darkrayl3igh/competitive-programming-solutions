// https://codeforces.com/problemset/problem/230/A
#include <bits/stdc++.h>

using namespace std;

vector< pair<int,int> > quest;
int s,n,x,y;

int main(){

    cin>>s>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        pair<int,int> duel;
        duel.first=x;duel.second=y;
        quest.push_back(duel);
    }
    sort(quest.begin(),quest.end());
    bool flag=true;
    for(int i=0;i<n;i++){
        if(quest[i].first>=s){flag=false;break;}
        else{s=s+quest[i].second;}
    }
    if(flag){cout<<"YES";}
    else{cout<<"NO";}
    return 0;
}