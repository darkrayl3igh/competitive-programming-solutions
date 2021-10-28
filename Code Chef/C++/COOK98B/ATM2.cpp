//https://www.codechef.com/COOK98B/problems/ATM2/
#include <iostream>
using namespace std;

int a,n,t,k;
string s="";

int main() {
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>a;
			if(k>=a){
				k=k-a;
				s=s+'1';
			}
			else{
				s=s+'0';
			}
		}
	cout<<s<<endl;
	s="";
	}
	return 0;
}
