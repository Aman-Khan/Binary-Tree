    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        if(!root2) return root1;
        if(!root1) return root2;
        root2->val +=root1->val;
        root2->left = mergeTrees(root1->left, root2->left);
        root2->right = mergeTrees(root1->right, root2->right);
        return root2;
    }
