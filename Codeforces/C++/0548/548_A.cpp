// https://codeforces.com/problemset/problem/548/A
#include <iostream>

using namespace std;

bool checkPalindrome(string p)
{
	string o="";
	for(int i=p.size()-1;i>-1;i--)
	{
		o+=p[i];
	}
	if(p==o)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int k,len;
	string s,temp;
	bool flag=true;
	cin>>s>>k;
	if(s.size()%k!=0)
	{
		cout<<"NO";
		return 0;
	}
	len=s.size()/k;
	for(int i=0;i<k;i++)
	{
		temp="";
		for(int j=len*i;j<len*(i+1);j++)
		{
			temp+=s[j];
		}
		if(!checkPalindrome(temp))
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}