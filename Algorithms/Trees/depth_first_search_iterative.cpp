#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int val, Node* left = nullptr, Node* right = nullptr) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

Node* build_tree(vector<int>& arr, int idx = 0) {
    Node* root = new Node(arr[idx]);
    int n = arr.size();

    if(idx*2+1 < n) {
        root->left = build_tree(arr, idx*2+1);
    }

    if(idx*2+2 < n) {
        root->right = build_tree(arr, idx*2+2);
    }

    return root;
}

void inorder(Node* root) {
    stack<Node*> tracker;
    while(!tracker.empty() || root) {
        if(root) {
            tracker.push(root);
            root = root->left;
        } else {
            root = tracker.top(); tracker.pop();
            cout << root->val << " ";
            root = root->right;
        }
    }
}

void preorder(Node* root) {
    stack<Node*> tracker;
    while(!tracker.empty() || root) {
        if(root) {
            tracker.push(root);
            cout << root->val << " ";
            root = root->left;
        } else {
            root = tracker.top(); tracker.pop();
            root = root->right;
        }
    }
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

    Node* root = build_tree(arr);

    return 0;
}