#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    int count;
    UnionFind(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        rank.resize(n, 1);
        count = n;
    }
    
    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        
        return parent[node];
    }
    
    bool union_(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) {
            return false;
        }
        count--;
        
        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
            rank[parent_x] += rank[parent_y];
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y] += rank[parent_x];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
