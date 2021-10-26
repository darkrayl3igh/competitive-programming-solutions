// https://codeforces.com/problemset/problem/200/B
#include <iostream>
 
using namespace std;
 
int main()
{
	double v=0.000000,p,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		v+=p/100;
	}
	cout<<v/n*100;
	return 0;
}