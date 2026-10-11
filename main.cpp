#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Insert value into BST
Node* insertNode(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) root->left = insertNode(root->left, v);
    else root->right = insertNode(root->right, v);
    return root;
}

// Find kth largest value via reverse inorder traversal
void kthLargest(Node* node, int& k, int& ans) {
    if (!node || k == 0) return;
    kthLargest(node->right, k, ans);
    if (k == 0) return;
    if (--k == 0) { ans = node->val; return; }
    kthLargest(node->left, k, ans);
}

int main() {
    // Read entire stdin, extract integers
    string input, line;
    while (getline(cin, line)) {
        input += line;
        input += ' ';
    }
    // Replace non-digit and non-minus with spaces
    for (char &c : input) {
        if (!(isdigit(c) || c == '-')) c = ' ';
    }
    stringstream ss(input);
    vector<int> nums;
    int x;
    while (ss >> x) nums.push_back(x);
    if (nums.empty()) return 0;
    int cnt = nums.back();
    nums.pop_back(); // remaining are tree node values in level order
    Node* root = nullptr;
    for (int v : nums) {
        root = insertNode(root, v);
    }
    int ans = -1;
    int k = cnt;
    kthLargest(root, k, ans);
    if (ans != -1) cout << ans << '\n';
    return 0;
}

