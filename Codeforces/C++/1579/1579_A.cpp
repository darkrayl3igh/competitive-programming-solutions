// http://codeforces.com/problemset/problem/1579/A
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <string>  
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector<int> VI; 
typedef vector<long long> VLL;

#define LL long long 
#define ULL unsigned long long
#define UI unsigned int
#define US unsigned short
#define F(i,L,R) for (int i = L; i < R; i++)
#define FR(i,R,L) for (int i = R; i >= L; i--)
#define FA(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
#define PB push_back
#define MP make_pair
#define VIP(a) int temp;cin>>temp;a.PB(temp)
#define ALL(a) a.begin(), a.end()
#define NEWLINE cout<<"\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL) 

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int a = 0, b = 0, c = 0;
        for (int i = 0;i < s.length(); i++){
            if (s[i] == 'A') a++;
            else if (s[i] == 'B') b++;
            else c++;
        }
        if (a + c == b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}