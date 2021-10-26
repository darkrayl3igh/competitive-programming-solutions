// https://codeforces.com/problemset/problem/705/A
#include <iostream>

using namespace std;

int main()
{
	int n;
	string s="",perm="";
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		if(i%2==1)
		{
			s+="I hate that ";
		}
		else
		{
			s+="I love that ";
		}
	}
	for(int i=0;i<s.size()-5;i++)
	{
		perm+=s[i];
	}
	perm+="it";
	cout<<perm;
	return 0;
}