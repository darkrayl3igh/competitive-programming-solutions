// https://codeforces.com/problemset/problem/580/A
#include <iostream>
#include <algorithm>

using namespace std;

int n,old=-9999999999999999999999999999999,nawa,counter=0,maxcounter=0;
bool flag;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nawa;
        if(nawa>=old){
            counter++;
            if(counter>maxcounter){
                maxcounter=counter;
            }
            old=nawa;
        }
        else{
            counter=1;
            old=nawa;
        }
    }
    cout<<maxcounter;
    return 0;
}