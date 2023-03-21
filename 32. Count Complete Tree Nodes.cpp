    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = 1;
        int rh = 1;
        TreeNode* tleft = root;
        TreeNode* tright = root;
        while(tleft->left){
            lh++;
            tleft = tleft->left;
        }
        while(tright->right){
            rh++;
            tright = tright->right;
        }
        if(lh==rh) return pow(2, lh)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
