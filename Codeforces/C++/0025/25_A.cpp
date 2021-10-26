//https://codeforces.com/problemset/problem/25/A
#include <bits/stdc++.h>

using namespace std;

int n,e=0,o=0;

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(e<2&&o<2){
            if(a[i]%2==0){e++;}
            else{o++;}
        }
    }
    if(e==2){
        for(int i=0;i<n;i++){
            if(a[i]%2==1){cout<<i+1;break;}
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]%2==0){cout<<i+1;break;}
        }
    }
    return 0;
}