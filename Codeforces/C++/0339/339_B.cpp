// https://codeforces.com/problemset/problem/339/B
#include <bits/stdc++.h>

using namespace std;

long long int n,m,house,counter=0;
vector<int> tasks;

int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>house;tasks.push_back(house);
    }
    for(int i=0;i<m-1;i++){
        if(tasks[i]>tasks[i+1]){counter++;}
    }
    cout<<(counter*n)+house-1;
    return 0;

}