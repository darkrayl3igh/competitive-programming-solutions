// https://codeforces.com/problemset/problem/266/B
#include <iostream>
#include <cmath>

using namespace std;

string s,o="";
int n,t;

int main(){
    cin>>n>>t;
    cin>>s;
    for(int i=0;i<t;i++){
        int j=0;
        while(j<n){
            if(s[j]=='B'&&s[j+1]=='G'){
                o=o+"G";
                o=o+"B";
                j=j+2;
            }
            else{
                o=o+s[j];
                j++;
            }
        }
    s=o;
    o="";
    }
    cout<<s;
    return 0;
}