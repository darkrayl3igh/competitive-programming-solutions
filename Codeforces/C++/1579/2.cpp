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

void rotate(vector<int>& arr, int l, int r) {
    int temp = arr[l];
    for(int i = l; i < r; i++) {
        arr[i] = arr[i+1];
    }
    arr[r] = temp;
}

int main(){
    FASTIO;
    
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> orig(n), sorted(n);
        unordered_map <int, int> origHash;
        for (int i = 0; i < n; i++){
            cin >> orig[i];
            sorted[i] = orig[i];
        }
        sort(sorted.begin(), sorted.end());
        
        vector <vector<int>> ans;
        for (int i = 0; i < n; i++){
            if (orig[i] != sorted[i]){
                int pos;
                for (int j = i + 1; j < n; j++){
                    if (orig[j] == sorted[i]){
                        pos = j;
                        break;
                    }
                }
                ans.push_back({i + 1, pos + 1, pos - i});
                for (int j = 0; j < pos - i; j++){
                    rotate(orig, i, pos);
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto itr : ans){
            cout << itr[0] << " " << itr[1] << " " << itr[2] << "\n";
        }
        
    }
    return 0;
}
