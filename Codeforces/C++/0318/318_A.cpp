// https://codeforces.com/problemset/problem/318/A
#include <iostream>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    if(n%2==1){
        if(k-((n/2)+1)>0){
            cout<<2+(((k-((n/2)+1))-1)*2);
        }
        else{
            cout<<1+((k-1)*2);
        }
    }
    else{
        if(k-(n/2)>0){
            cout<<2+(((k-(n/2))-1)*2);
        }
        else{
            cout<<1+((k-1)*2);
        }
    }
    return 0;
}