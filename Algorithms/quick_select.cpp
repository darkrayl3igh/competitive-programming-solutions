#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high, int idx) {
    int pivot = arr[idx];
 
    swap(arr[idx], arr[high]);
 
    idx = low;
 
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
 
    swap(arr[idx], arr[high]);
 
    return idx;
}

int quick_select(vector<int>& arr, int low, int high, int k) {
    if(low == high) {
        return arr[low];
    }

    int idx = (rand() % (high + 1 - low)) + low;
    idx = partition(arr, low, high, idx);

    int target = arr.size() - k;
    if(idx == target) {
        return arr[idx];
    } else if(idx < target) {
        return quick_select(arr, idx + 1, high, k);
    }

    return quick_select(arr, low, idx - 1, k);
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

    cout << quick_select(arr, 0, arr.size() - 1, 2);

    return 0;
}