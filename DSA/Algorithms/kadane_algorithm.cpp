//used to find longest subarray sum
//time complexity O(n)
//space complexity O(1)

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max_sum = INT_MIN, running_sum = 0;
    for(int i = 0; i < n; i++) {
        running_sum = max(arr[i], running_sum + arr[i]);    //add element to running sum or start a new running sum
        max_sum = max(max_sum, running_sum);
    }

    cout << max_sum << endl;

    return 0;
}