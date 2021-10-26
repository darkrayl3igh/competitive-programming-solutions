// https://codeforces.com/problemset/problem/849/A
#include <iostream>

using namespace std;

int main()
{
	int n,d,counter=0;
	cin>>n;
	int values[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>d;
		if(d%2==1)
		{
			values[i]=1;
			counter++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(values[i]==1)
		{
			for(int j=i+1;j<n;j++)
			{
				if(values[j]==1)
				{
					if((j-i)%2==0&&(j-1)!=n)
					{
						counter++;
					}
				}
			}
		}
	}
	if(counter%2==1)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}