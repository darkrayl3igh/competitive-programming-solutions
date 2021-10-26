// https://codeforces.com/problemset/problem/486/A
#include <iostream>

using namespace std;

int main(){
    long long int n,counter=0;
    cin>>n;
    if(n%2==0){
        cout<<n/2;
    }
    else{
        cout<<-1*((1+n)/2);
    }
    return 0;
}