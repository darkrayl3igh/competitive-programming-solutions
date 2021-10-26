// https://codeforces.com/problemset/problem/479/A
#include <iostream>
#include <algorithm>

using namespace std;

int a,b,c;

int main()
{
    cin>>a>>b>>c;
    cout<<max((a+b+c),max((a+b*c),max((a*b+c),max((a*b*c),max(((a+b)*c),max(((a*b)+c),max((a+(b*c)),(a*(b+c)))))))));
    return 0;
}