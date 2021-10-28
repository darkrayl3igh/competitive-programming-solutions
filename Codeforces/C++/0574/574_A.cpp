// https://codeforces.com/problemset/problem/574/A
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{	
	int n,baseValue;
	cin>>n;
	int votes[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>votes[i];
	}
	baseValue=votes[0];
	sort(votes+1,votes+n);
	while(votes[0]<=votes[n-1])
	{
		votes[n-1]-=1;
		votes[0]+=1;
		sort(votes+1,votes+n);
	}
	cout<<votes[0]-baseValue;
	return 0;
}