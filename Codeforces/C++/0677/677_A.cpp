// https://codeforces.com/problemset/problem/677/A
#include <iostream>

using namespace std;

int main()
{
	int n,h,w=0,a;
	cin>>n>>h;
	while(n--)
	{
		cin>>a;
		if(a>h)
		{
			w+=2;
		}
		else
		{
			w+=1;
		}
	}
	cout<<w;
	return 0;
}