#include <bits/stdc++.h>

using namespace std;

struct Node{
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
    if(root->left) {
        inorder(root->left);
    }
    
    cout << root->val << " ";
    
    if(root->right) {
        inorder(root->right);
    }
}

void preorder(Node* root) {
    cout << root->val << " ";
    
    if(root->left) {
        preorder(root->left);
    }
    
    if(root->right) {
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if(root->left) {
        postorder(root->left);
    }
    
    if(root->right) {
        postorder(root->right);
    }

    cout << root->val << " ";
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = build_tree(arr);

    inorder(root);   

    return 0;
}