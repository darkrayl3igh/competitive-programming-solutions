// https://codeforces.com/problemset/problem/131/A
#include <iostream>
#include <cmath>

using namespace std;

string s;
int flag=1;

int main(){
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(islower(s[i])){
            flag=0;
        }
    }
    if(flag){
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){
                cout<<char(s[i]+32);
            }
            else{
                cout<<char(s[i]-32);
            }
        }
    }
    else{
        cout<<s;
    }
    return 0;
}