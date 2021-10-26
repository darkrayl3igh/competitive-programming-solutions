// https://codeforces.com/problemset/problem/451/A
#include<iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n;
	cin>>m;
    if(n>=m)
	{
		n=m;
	}
	if(n%2==0)
	{
		cout<<"Malvika"<<endl;
	}
	else
	{
		cout<<"Akshat"<<endl;
	}
	return 0;
}