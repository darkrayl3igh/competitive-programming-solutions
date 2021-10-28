// https://codeforces.com/problemset/problem/160/A
#include <iostream>
#include <cmath>

using namespace std;

int n,total=0,mid=0,cnt=0,final=0;
int s[100];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        total=total+s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;(j<(n-i-1));j++){
            if(s[j]>s[j+1]){
                mid=s[j];
                s[j]=s[j+1];
                s[j+1]=mid;
            }
        }
    }
    for(int i=n-1;i>-1;i--){
        cnt=cnt+s[i];
        final++;
        if(cnt>(floor(total/2))){
            break;
        }
    }
    cout<<final;
    return 0;
}