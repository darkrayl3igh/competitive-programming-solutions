// https://codeforces.com/problemset/problem/1066/B
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,r,p,q,count1=0,f=0;
    cin >> n >>r;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    	if(a[i])
    		count1++;
    }

    vector<int> v(n,0);
    for (int i = 0; i < n; ++i)
    {
    	if(a[i])
    	{
    		if(i-r+1>=0)
    			p=i-r+1;
    		else
    			p=0;
    		if(i+r-1<n)
    			q=i+r-1;
    		else
    			q=n-1;
    		for (int j=p; j <=q ; ++j)
    			v[j]++;
    	}
    }
    for (int i = 0; i < n; ++i)
    {

    	if(v[i]==0)
    	{
    		cout << -1 << "\n";
    		return 0;
    	}
    }
    int count=0;
    for (int i = 0; i < n; ++i)
    {
    	if(a[i])
    	{	f=0;
    		if(i-r+1>=0)
    			p=i-r+1;
    		else
    			p=0;
    		if(i+r-1<n)
    			q=i+r-1;
    		else
    			q=n-1;
    		for (int j=p; j <=q ; ++j)
    		{
    			if(v[j]==1)
    			{
    				f=1;
    				break;
    			}
    		}
    		if(f==0)
    		{
    			count++;
    			for (int j=p; j <=q ; ++j)
    				v[j]--;
    		}
    	}
    }
    cout << count1-count << "\n";

}