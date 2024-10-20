/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorderTraversal(TreeNode *root, vector<int> &inorder) {
    if (!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Helper function to perform preorder traversal
void preorderTraversal(TreeNode *root, vector<int> &preorder) {
    if (!root) return;
    preorder.push_back(root->data);
    preorderTraversal(root->left, preorder);
    preorderTraversal(root->right, preorder);
}

// Helper function to perform postorder traversal
void postorderTraversal(TreeNode *root, vector<int> &postorder) {
    if (!root) return;
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<int> inorder, preorder, postorder;
    
    // Populate each traversal
    inorderTraversal(root, inorder);
    preorderTraversal(root, preorder);
    postorderTraversal(root, postorder);

    // Return all traversals as a vector of vectors
    return {inorder, preorder, postorder};
}