#include <bits/stdc++.h>

using namespace std;

class Queue {
    vector<int> tracker;
public:
    void push(int val) {
        tracker.insert(tracker.begin(), val);
    }

    void pop() {
        tracker.pop_back();
    }

    int front() {
        return tracker.back();
    }

    bool empty() {
        return !tracker.size();
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    Queue tracker;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tracker.push(temp);
    }

    while(!tracker.empty()) {
        cout << tracker.front() << " ";
        tracker.pop();
    }

    return 0;
}