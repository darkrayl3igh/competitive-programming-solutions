// https://codeforces.com/problemset/problem/431/A
#include <iostream>

using namespace std;

int main()
{
	int stripes[5]={0},sum=0;
	string s;
	
	for(int i=1;i<5;i++)
	{
		cin>>stripes[i];
	}
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		sum+=stripes[s[i]-48];
	}
	cout<<sum;
	return 0;
}