// https://codeforces.com/problemset/problem/427/A
#include <iostream>

using namespace std;

int main()
{
	int n,totalCrime=0,crime=0,police=0,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		if(m>0)
		{
			police+=m;
		}
		else
		{
			crime-=m;
		}
		if(police>=crime)
		{
			police-=crime;
			crime=0;
		}
		else
		{
			crime-=police;
			police=0;
		}
		if(crime>0)
		{
			totalCrime+=crime;
			crime=0;
		}
	}
	cout<<totalCrime;
	return 0;
}