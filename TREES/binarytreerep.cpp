class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        root0->data = vec[0];

    root0->left = NULL;
    root0->right = NULL;
    create_tree(root0->left, vec);
    create_tree(root0->right, vec);

    }

};