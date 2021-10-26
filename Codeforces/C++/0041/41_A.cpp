// https://codeforces.com/problemset/problem/41/A
#include <iostream>
#include <cmath>

using namespace std;

string s,t,o="";


int main(){
    cin>>s>>t;
    if(s.size()!=t.size()){
        cout<<"NO";
    }
    else{
        for(int i=s.size()-1;i>-1;i=i-1){
            o=o+s[i];
        }
        if(o==t){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }

    return 0;
}