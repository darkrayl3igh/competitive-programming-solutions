// https://codeforces.com/problemset/problem/144/A
#include <iostream>

using namespace std;

int main()
{
	int n,a,max=0,min=101,maxi=0,mini=101l;
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		cin>>a;
		if(a>max)
		{
			max=a;
			maxi=i;
		}
		if(a<=min)
		{
			min=a;
			mini=i;
		}
	}
	//cout<<max<<" "<<maxi<<" "<<min<<" "<<mini<<endl;
	if(maxi-mini>0)
	{
		cout<<maxi-1+n-mini-1;
	}
	else
	{
		cout<<maxi-1+n-mini;
	}
	return 0;
}