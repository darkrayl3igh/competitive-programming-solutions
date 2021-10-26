// https://codeforces.com/problemset/problem/271/A
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string s;
int y;

int checker(int a){
    s=to_string(a);
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    cin>>y;
    while(true){
        if(checker(y+1)==0){
            y++;
        }
        else{
            cout<<y+1;
            break;
        }
    }
    return 0;
}