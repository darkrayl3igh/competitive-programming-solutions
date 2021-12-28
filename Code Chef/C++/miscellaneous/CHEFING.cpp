#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,secret=0,i=0;
    vector<int> alphabets(26);
    string ingredients;
    cin>>t;
    while(t--)
    {
        vector<int> a(26,0);
        secret=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>ingredients;
            for(i=0;i<ingredients.size();i++)
            {
                alphabets[ingredients[i]-97]=1;
            }
            for(i=0;i<26;i++)
                if(alphabets[i]==1) a[i]++;

            for(i=0;i<26;i++) alphabets[i]=0;

        }
        for(i=0;i<26;i++)
        {
            if(a[i]==n) secret++;
        }
        cout<<secret<<endl;
    }
    return 0;
}
