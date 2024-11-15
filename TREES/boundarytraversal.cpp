void addLeftBoundary(Node *root, vector<int> &ans) {
    Node *curr = root->left;
    while (curr) {
        if (!curr->left && !curr->right) ans.push_back(curr->data);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(Node *root, vector<int> &ans) {
    Node *curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!curr->left && !curr->right) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) ans.push_back(temp[i]);
}

void addLeaves(Node *root, vector<int> &ans) {
    if (root->left) addLeaves(root->left, ans);
    if (!root->left && !root->right) ans.push_back(root->data);
    if (root->right) addLeaves(root->right, ans);
}
