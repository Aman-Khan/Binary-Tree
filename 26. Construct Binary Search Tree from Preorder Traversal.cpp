//O(3N), O(1)
    TreeNode* buildBST(vector<int>& preorder, int &i, int mini, int maxi, int n){
        if(i>=n) return NULL;
        if(preorder[i]<mini || preorder[i]>maxi) return NULL;
        int ele = preorder[i++];
        TreeNode* root = new TreeNode(ele);
        root->left = buildBST(preorder, i, mini, ele, n);
        root->right = buildBST(preorder, i, ele, maxi, n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i=0;
        return buildBST(preorder, i, mini, maxi, preorder.size());
    }


//O(NLogN), O(N)
    int findPostion(vector<int>& inorder, int ele){
        int ind = -1;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i]==ele) return i;
        }
        return ind;
    }
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int &index, int ioStart, int ioEnd, int n){
        if(index>=n || ioStart>ioEnd) return NULL;
        int ele = preorder[index++];
        TreeNode* root = new TreeNode(ele);
        int position = findPostion(inorder, ele);
        root->left = build(preorder, inorder, index, ioStart, position-1, n);
        root->right = build(preorder, inorder, index, position+1, ioEnd, n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int index=0;
        int n = preorder.size();
        TreeNode* root = build(preorder, inorder, index, 0, n-1, n);
        return root;
    }
