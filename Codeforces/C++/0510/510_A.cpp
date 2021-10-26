// https://codeforces.com/problemset/problem/510/A
#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n+1;i++)
	{
		if(i%2==1)
		{
			for(int j=0;j<m;j++)
			{
				cout<<"#";
			}
			cout<<endl;
		}
		else if((i/2)%2==1)
		{
			for(int j=0;j<m-1;j++)
			{
				cout<<".";
			}
			cout<<"#"<<endl;
		}
		else
		{
			cout<<"#";
			for(int j=0;j<m-1;j++)
			{
				cout<<".";
			}
			cout<<endl;
		}
	}
	return 0;
}