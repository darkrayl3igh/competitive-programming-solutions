#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    string a;
    cin>>t;

    while(t--)
    {
        int sum=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c10=0,c11=0,c12=0,c13=0,c14=0,c15=0,c16=0,c17=0,c18=0,c19=0,c20=0,c21=0,c22=0,c23=0,c24=0,c25=0,c26=0,c27=0,c28=0,c29=0,c30=0,c31=0,c32=0;
        cin>>n;
        while(n--)
        {
            int v[5]={0};
            cin>>a;
            for(int i=0;i<a.size();i++)
            {
                if(a[i]=='a') v[0]=1;
                if(a[i]=='e') v[1]=1;
                if(a[i]=='i') v[2]=1;
                if(a[i]=='o') v[3]=1;
                if(a[i]=='u') v[4]=1;
            }
            if(v[0]==1&&v[1]==1&&v[2]==1&&v[3]==1&&v[4]==1) c1++;

            if(v[0]==1&&v[1]==1&&v[2]==1&&v[3]==1&&v[4]==0) c2++;
            if(v[0]==1&&v[1]==1&&v[2]==1&&v[3]==0&&v[4]==1) c3++;
            if(v[0]==1&&v[1]==1&&v[2]==0&&v[3]==1&&v[4]==1) c4++;
            if(v[0]==1&&v[1]==0&&v[2]==1&&v[3]==1&&v[4]==1) c5++;
            if(v[0]==0&&v[1]==1&&v[2]==1&&v[3]==1&&v[4]==1) c6++;

            if(v[0]==1&&v[1]==1&&v[2]==1&&v[3]==0&&v[4]==0) c7++;
            if(v[0]==1&&v[1]==1&&v[2]==0&&v[3]==0&&v[4]==1) c8++;
            if(v[0]==1&&v[1]==0&&v[2]==0&&v[3]==1&&v[4]==1) c9++;
            if(v[0]==0&&v[1]==0&&v[2]==1&&v[3]==1&&v[4]==1) c10++;

            if(v[0]==1&&v[1]==1&&v[2]==0&&v[3]==1&&v[4]==0) c11++;
            if(v[0]==1&&v[1]==0&&v[2]==1&&v[3]==0&&v[4]==1) c12++;
            if(v[0]==0&&v[1]==1&&v[2]==0&&v[3]==1&&v[4]==1) c13++;

            if(v[0]==1&&v[1]==0&&v[2]==1&&v[3]==1&&v[4]==0) c14++;
            if(v[0]==0&&v[1]==1&&v[2]==1&&v[3]==0&&v[4]==1) c15++;

            if(v[0]==0&&v[1]==1&&v[2]==1&&v[3]==1&&v[4]==0) c16++;

            if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0) c17++;

            if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==1) c18++;
            if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==1&&v[4]==0) c19++;
            if(v[0]==0&&v[1]==0&&v[2]==1&&v[3]==0&&v[4]==0) c20++;
            if(v[0]==0&&v[1]==1&&v[2]==0&&v[3]==0&&v[4]==0) c21++;
            if(v[0]==1&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0) c22++;

            if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==1&&v[4]==1) c23++;
            if(v[0]==0&&v[1]==0&&v[2]==1&&v[3]==1&&v[4]==0) c24++;
            if(v[0]==0&&v[1]==1&&v[2]==1&&v[3]==0&&v[4]==0) c25++;
            if(v[0]==1&&v[1]==1&&v[2]==0&&v[3]==0&&v[4]==0) c26++;

            if(v[0]==0&&v[1]==0&&v[2]==1&&v[3]==0&&v[4]==1) c27++;
            if(v[0]==0&&v[1]==1&&v[2]==0&&v[3]==1&&v[4]==0) c28++;
            if(v[0]==1&&v[1]==0&&v[2]==1&&v[3]==0&&v[4]==0) c29++;

            if(v[0]==0&&v[1]==1&&v[2]==0&&v[3]==0&&v[4]==1) c30++;
            if(v[0]==1&&v[1]==0&&v[2]==0&&v[3]==1&&v[4]==0) c31++;

            if(v[0]==1&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==1) c32++;
        }
        sum+=(c1-1)*c1/2;
        sum+=c1*(c2+c3+c4+c5+c6+c7+c8+c9+c10+c11+c12+c13+c14+c15+c16+c17+c18+c19+c20+c21+c22+c23+c24+c25+c26+c27+c28+c29+c30+c31+c32);
        sum+=c2*(c3+c4+c5+c6+c8+c9+c10+c12+c13+c15+c18+c23+c27+c30+c32);
        sum+=c3*(c4+c5+c6+c9+c10+c11+c13+c14+c16+c19+c23+c24+c28+c31);
        sum+=c4*(c5+c6+c7+c10+c12+c14+c15+c16+c20+c24+c25+c27+c29);
        sum+=c5*(c6+c7+c8+c11+c13+c15+c16+c21+c25+c26+c28+c30);
        sum+=c6*(c7+c8+c9+c11+c12+c14+c22+c26+c29+c31+c32);
        sum+=c7*(c9+c10+c13+c23);
        sum+=c8*(c10+c14+c16+c24);
        sum+=c9*(c15+c16+c25);
        sum+=c10*(c11+c26);
        sum+=c11*(c12+c15+c27);
        sum+=c12*(c13+c16+c28);
        sum+=c13*(c14+c29);
        sum+=c14*(c15+c30);
        sum+=c15*c31;
        sum+=c16*c32;
        cout<<sum<<endl;
    }
    return 0;
}
