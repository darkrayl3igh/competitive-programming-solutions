// https://codeforces.com/problemset/problem/208/A
#include <iostream>

using namespace std;

int main(){
    string s,o="",p="",q="";
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
            o=o+" ";
            i=i+2;
        }
        else{
            o=o+s[i];
        }
    }
    for(int i=0;i<o.size();i++){
        if(o[i]==' '&&o[i+1]!=' '){
            p=p+" ";
        }
        else if(o[i]!=' '){
            p=p+o[i];
        }
    }
    if(p[0]==' '&&p[p.size()-1]==' '){
            for(int i=1;i<p.size()-1;i++){
                q=q+p[i];
            }
    cout<<q;
    }
    else if(p[0]==' '&&p[p.size()-1]!=' '){
        for(int i=1;i<p.size();i++){
            q=q+p[i];
        }
    cout<<q;
    }
    else if(p[0]!=' '&&p[p.size()-1]==' '){
        for(int i=0;i<p.size()-1;i++){
            q=q+p[i];
        }
    cout<<q;
    }
    else{
        cout<<p;
    }
    return 0;
}