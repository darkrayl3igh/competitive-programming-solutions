// https://codeforces.com/problemset/problem/520/B
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,m,i=0;
	cin>>n>>m;
	while(n*2<m)
	{
		i++;
		n*=2;
	}
	cout<<i+abs(n-m);
	return 0;
}