#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int idx = (rand() % (high+1-low)) + low;
    int pivot = arr[idx];

    swap(arr[high], arr[idx]); idx = low;
    for(int i = 0; i < high; i++) {
        if(arr[i] < arr[high]) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }

    swap(arr[idx], arr[high]);
    return idx;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << partition(arr, 0, n-1);

    return 0;
}