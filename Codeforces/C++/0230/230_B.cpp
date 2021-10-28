// https://codeforces.com/problemset/problem/230/B
#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    if(n==1) return false;
    int count=0;
    for(int i=2;i*i<=n;i++){
        if(n%i ==0) return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int count=0;
        if(ceil(sqrt(n))==floor(sqrt(n))){
            int ans=sqrt(n);
            if(prime(ans)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
	return 0;
}