#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,l,counter;
    string s;
    cin>>t;
    while(t--)
    {
        counter=0;
        cin>>l;
        cin>>s;
        for(int i=0;i<l;i++)
        {
            if(counter==0)
            {
                if(s[i]=='c') counter++;
            }
            if(counter==1)
            {
                if(s[i]=='o') counter++;
            }
            if(counter==2)
            {
                if(s[i]=='d') counter++;
            }
            if(counter==3)
            {
                if(s[i]=='e') counter++;
            }
            if(counter==4)
            {
                if(s[i]=='r') counter++;
            }
            if(counter==5)
            {
                if(s[i]=='e') counter++;
            }
            if(counter==6)
            {
                if(s[i]=='d') counter++;
            }
        }
        if(counter==7) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
