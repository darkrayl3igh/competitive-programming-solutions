// https://codeforces.com/problemset/problem/275/A
#include <iostream>

using namespace std;

int main()
{
	int matrix[5][5];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			matrix[i][j]=0;
		}
	}


	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			cin>>matrix[i][j];
		}
	}

	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if((matrix[i-1][j]+matrix[i+1][j]+matrix[i][j+1]+matrix[i][j-1]+matrix[i][j])%2==0)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		cout<<endl;
	}
	return 0;
}