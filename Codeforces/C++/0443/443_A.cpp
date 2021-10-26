// https://codeforces.com/problemset/problem/443/A
#include <bits/stdc++.h>

using namespace std;

string s;
int a[27]={0};
int counter=0;

int main(){
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]<123 &&s[i]>96){a[s[i]-96]=1;}
    }

    for(int i=0;i<27;i++){
        if(a[i]==1){counter++;}
    }
    cout<<counter;
    return 0;
}