    TreeNode* findNode(TreeNode* root, int target){
        if(!root) return NULL;
        if(root->val==target) return root;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if(root->val>target){
            left = findNode(root->left, target);
        }
        else if(root->val<target){
            right = findNode(root->right, target);
        }
        if(!left && !right) return NULL;
        if(!left) return right;
        else return left;
    }
    bool twoSum(TreeNode* root, TreeNode* real, int k){
        if(!root) return false;
        TreeNode* get = findNode(real, k-root->val);
        if(get!=NULL && get!=root) return true;
        return twoSum(root->left, real, k) || twoSum(root->right, real, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return twoSum(root, root, k);
    }
