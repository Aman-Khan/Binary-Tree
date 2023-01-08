 void inOrder(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
    TreeNode* buildBST(vector<int> &inorder, int s, int e){
        if(s>e) return NULL;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left= buildBST(inorder, s, mid-1);
        root->right= buildBST(inorder, mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        int n = inorder.size();
        TreeNode* ans = buildBST(inorder, 0, n-1);
        return ans;
    }
