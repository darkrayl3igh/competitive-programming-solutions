//https://www.codechef.com/COOK98B/problems/MAKPERM/
#include <iostream>
#include <algorithm>

using namespace std;

int n,t,counter=0,m;

int main() {
	cin>>t;
	for(int l=0;l<t;l++){
	int a[100005]={0};
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>m;
			if(m<=n){
				a[m-1]=1;
			}
		}
	for(int k=0;k<n;k++){
		if(a[k]==0){
			counter++;
		}
	}
	cout<<counter<<endl;
	counter=0;
	}
	return 0;
}
