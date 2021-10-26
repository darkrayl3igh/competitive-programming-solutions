// https://codeforces.com/problemset/problem/133/A
#include <iostream>
#include <cmath>

using namespace std;

string s;
int flag=1;

int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isupper(s[i])){
             if(s[i]=='H'||s[i]=='Q'){
                cout<<"YES";
                flag=0;
                break;
             }
        }
        else if(s[i]=='9'){
            cout<<"YES";
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"NO";
    }
    return 0;
}