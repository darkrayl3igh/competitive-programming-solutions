// https://codeforces.com/problemset/problem/136/A
#include <iostream>

using namespace std;

int a[101],b;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++){
        cin>>b;
        a[b]=i;
    }
    for(int i=1;i<n+1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}