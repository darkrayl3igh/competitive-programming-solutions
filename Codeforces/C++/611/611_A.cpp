// https://codeforces.com/problemset/problem/611/A
#include <iostream>

using namespace std;

int a;
string b,c;

int main()
{
	cin>>a>>b>>c;
	if(c=="week")
	{
		if(a!=5&&a!=6){cout<<52;}
		else{cout<<53;}
	}
	else
	{
		if(a==31){cout<<7;}
		else if(a==30){cout<<11;}
		else{cout<<12;}
	}
	return 0;
}