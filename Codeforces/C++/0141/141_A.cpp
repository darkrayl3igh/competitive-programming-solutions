// https://codeforces.com/problemset/problem/141/A
#include <bits/stdc++.h>

using namespace std;

vector<int> va(26);
vector<int> vc(26);
string a,b,c;
bool flag=true;

int main(){
    cin>>a>>b>>c;
    for(int i=0;i<a.size();i++){va[a[i]-65]++;}
    for(int i=0;i<b.size();i++){va[b[i]-65]++;}
    for(int i=0;i<c.size();i++){vc[c[i]-65]++;}
    for(int i=0;i<va.size();i++){
        if(vc[i]!=va[i]){flag=false;break;}
    }
    if(flag){cout<<"YES";}
    else{cout<<"NO";}
    return 0;
}