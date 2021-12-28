#include <bits/stdc++.h>

using namespace std;

class Stack {
    vector<int> tracker;
public:
    void push(int val) {
        tracker.push_back(val);
    }

    void pop() {
        tracker.pop_back();
    }

    int top() {
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
    Stack tracker;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        tracker.push(temp);
    }

    while(!tracker.empty()) {
        cout << tracker.top() << " ";
        tracker.pop();
    }

    return 0;
}