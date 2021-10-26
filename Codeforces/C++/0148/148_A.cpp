// https://codeforces.com/problemset/problem/148/A
#include <iostream>

using namespace std;

int k,l,m,n,d;
int counter=0;

int main(){
    cin>>k>>l>>m>>n>>d;
    for(int i=1;i<d+1;i++){
        if(i%k==0){
            counter++;
        }
        else if(i%l==0){
            counter++;
        }
        else if(i%m==0){
            counter++;
        }
        else if(i%n==0){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}