// https://codeforces.com/problemset/problem/82/A
#include <iostream>

using namespace std;

int main()
{
    int n;
    string tbbt[]={ "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    cin>>n;
    n--;
    while(n>=5){
        n=n-5;
        n=n/2;
    }
    cout<<tbbt[n];
    return 0;
    
}