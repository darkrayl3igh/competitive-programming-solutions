// https://codeforces.com/problemset/problem/467/A
#include <iostream>
#include <cmath>

using namespace std;

int n,p,q,counter;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>q;
        if((q-p)>1){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}