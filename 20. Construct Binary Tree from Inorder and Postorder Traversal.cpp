    TreeNode* build(vector<int>& inorder, vector<int>& postorder, map<int, int> &tMap, int& index, int ioStart, int ioEnd){
        if(index<0 || ioStart>ioEnd) return NULL;
        int element = postorder[index--];
        TreeNode* temp = new TreeNode(element);
        int position = tMap[element];
        temp->right = build(inorder, postorder, tMap, index, position+1, ioEnd);
        temp->left = build(inorder, postorder, tMap, index, ioStart, position-1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int, int> tMap;
        for(int i=0; i<n; i++){
            tMap[inorder[i]]=i;
        }
        int index=n-1;
        TreeNode* root = build(inorder, postorder, tMap, index, 0, n-1);
        return root;
    }
