// https://codeforces.com/problemset/problem/789/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,a;
	int counter=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a%k==0)
		{
			counter+=a/k;
		}
		else
		{
			counter+=a/k;
			counter++;
		}
	}
	if(counter%2==0)
	{
		cout<<counter/2;
	}
	else
	{
		cout<<(counter/2)+1;
	}
	return 0;
}