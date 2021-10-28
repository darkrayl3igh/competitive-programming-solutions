// http://codeforces.com/problemset/problem/1579/C
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

bool on_line(vector <vector <char>>& grid, int x, int y, int n, int m){
    if(x == 0){
        if (y == m - 1) return grid[x + 1][y - 1] == '*';
        if (y == 0) return grid[x + 1][y + 1] == '*';
        return grid[x + 1][y + 1] == '*' || grid[x + 1][y - 1] == '*'; 
    }
    if (x == n - 1){
        if (y == m - 1) return grid[x - 1][y - 1] == '*';
        if (y == 0) return grid[x - 1][y + 1] == '*';
        return grid[x - 1][y + 1] == '*' && grid[x - 1][y - 1] == '*'; 
    }
    if (y == 0){
        return grid[x + 1][y + 1] == '*' && grid[x - 1][y + 1] == '*'; 
    }
    if (y == m - 1){
        return grid[x - 1][y - 1] == '*' && grid[x + 1][y - 1] == '*'; 
    }
    return (grid[x - 1][y - 1] == '*' && grid[x + 1][y + 1] == '*') || (grid[x- 1][y + 1] == '*' && grid[x + 1][y - 1] == '*');
}

bool check(vector <vector <char>>& grid, int x, int y, int n, int m, int k){
    int size = 0;
    for (int i = 0; i < n; i++){
        if (grid[x - i][y + i] == grid[x - i][y - i]){
            size++;
        }
        else break;
    }
    if (size >= k) return true;
    return false;
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> n >> m >> k;
        vector <vector <char>> grid (n, vector <char> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        int flag = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '*' && !on_line(grid, i, j, n, m)){
                    if(!check(grid, i, j, n, m, k)) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}