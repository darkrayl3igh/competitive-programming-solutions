// https://codeforces.com/problemset/problem/158/B
#include <iostream>

using namespace std;

int main()
{
    int n,n1=0,n2=0,n3=0,n4=0,a,cars=0;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a==1){n1++;}
        else if(a==2){n2++;}
        else if(a==3){n3++;}
        else{n4++;}
    }
    cars+=n4;n4=0;
    if(n3>n1){cars+=n3;n3=0;n1=0;}
    else if(n3<n1){cars+=n3;n1-=n3;n3=0;}
    else{cars+=n3;n3=0;n1=0;}

    if(n2%2==0){cars+=n2/2;n2=0;}
    else{cars+=n2/2;n2=1;}

    if(n2==1&&n1>0){cars++;n2=0;n1-=2;}
    else if(n2==1){cars++;n2=0;}
    cars+=n1/4;n1%=4;

    if(n1>0){cars++;}
    cout<<cars;

    return 0;
}