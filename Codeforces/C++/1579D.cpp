#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL) 

int helper(int n){
    bitset<64> bit;
    bit |= n;
 
	int to_return = 0;
 
	for (int i = 0; i < 64; i++) {
		if (bit[i] == 0){
            to_return++;
        }
		else{
            break;
        }
	}
	return to_return;
}


int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            int num; cin >> num;
            if (num % 2 == 0){
                ans = min(ans, helper(num));
            }
        }
        if (ans == INT_MAX) cout << "0\n";
        else cout << ans << "\n";
    }

    return 0;
}