// https://codeforces.com/problemset/problem/686/A
#include <iostream>

using namespace std;

int main()
{
	long long int counter=0,n,x,d,total=0;
	char o;
	cin>>n>>x;
	total=x;
	for(long long int i=0;i<n;i++)
	{
		cin>>o>>d;
		if(o=='+')
		{
			total+=d;
		}
		else
		{
			if(total>=d)
			{
				total-=d;
			}
			else
			{
				counter++;
			}
		}
	}
	cout<<total<<" "<<counter;
	return 0;
}