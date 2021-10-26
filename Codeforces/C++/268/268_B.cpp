// https://codeforces.com/problemset/problem/268/B
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int counter=n;
    for(int i=1;i<n;i++)
    {
        counter=counter+(i*(n-i));
    }
    cout<<counter;
    return 0;
}