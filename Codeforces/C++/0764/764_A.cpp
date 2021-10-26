// https://codeforces.com/problemset/problem/764/A
#include <iostream>

using namespace std;

int main()
{
	int counter=0,n,m,z;
	cin>>n>>m>>z;
	for(int i=1;i<z+1;i++)
	{
		if(i%n==0&&i%m==0)
		{
			counter++;
		}
	}
	cout<<counter;
	return 0;
}