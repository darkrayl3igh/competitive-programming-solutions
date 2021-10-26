// https://codeforces.com/problemset/problem/279/B
#include <bits/stdc++.h>

using namespace std;

int  n,t,a;
int  l=0,r=0,sum=0,ans=0;
vector<int> books;

int main() {

     cin>>n>>t;
     for(int i=0;i<n;i++)
    {
        cin>>a;
        books.push_back(a);
    }
     while(r<n)
    {
         sum+=books[r];
         if(sum<=t)
         {
             ans=max(ans,(r-l+1));
         }
         while(sum>t)
        {
             sum-=books[l];
             l++;
         }
     r++;
     }
     cout<<ans;
}