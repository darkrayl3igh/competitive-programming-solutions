// https://codeforces.com/problemset/problem/228/A
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int shoes[4],counter=1;
    for(int i=0; i<4;i++)
    {
        cin>>shoes[i];
    }
    sort(shoes,shoes+4);
    for(int i=0; i<3;i++)
    {
        if(shoes[i] != shoes[i+1])
		{
			counter++;
 		}
	}
    cout<<(4-counter);
}