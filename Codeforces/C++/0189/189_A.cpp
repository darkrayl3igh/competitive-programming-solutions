// https://codeforces.com/problemset/problem/189/A
#include <bits/stdc++.h>
#define m(a,b,c) max(a,max(b,c))

using namespace std;

int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int length[n+1]={0};
	int value[3]={a,b,c};
	sort(value,value+3);
	
	for(int i=1;i<value[0];i++)
	{
		length[i]=-INT_MAX;
	}
	
	for(int i=0;i<n+1;i++)
	{
		if(i>=value[2])
		{
			length[i]=m(length[i-value[0]]+1,length[i-value[1]]+1,length[i-value[2]]+1);
		}
		else if(i>=value[1])
		{
			length[i]=max(length[i-value[0]]+1,length[i-value[1]]+1);	
		}
		else if(i>=value[0])
		{
			length[i]=length[i-value[0]]+1;
		}
	}
	cout<<length[n];
	return 0;
}