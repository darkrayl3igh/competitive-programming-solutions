// https://codeforces.com/problemset/problem/276/A
#include <iostream>

using namespace std;

int main()
{
	int n,k,f,t,max=-999999999;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>f>>t;
		if(t>k)
		{
			f=f-t+k;
		}
		if(f>max)
		{
			max=f;
		}
	}
	cout<<max;
	return 0;
}