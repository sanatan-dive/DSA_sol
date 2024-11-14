class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same
        if (p == nullptr && q == nullptr) return true;
        // If one is null and the other is not, they are not the same
        if (p == nullptr || q == nullptr) return false;
        // Check the value of the current nodes and recursively check the left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
