  //without map
    int findPosition(vector<int> &inorder, int ele, int n){
        for(int i=0; i<n; i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inOrderStart, int inOrderEnd, int n){
        if(index>=n || inOrderStart>inOrderEnd) return NULL;
        int element = preorder[index++];
        TreeNode* temp = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        temp->left = solve(preorder, inorder, index, inOrderStart, position-1, n);
        temp->right = solve(preorder, inorder, index, position+1, inOrderEnd, n);
        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n);
        return ans;
    }

//with map
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, map<int, int> tMap, int &index, int ioStart, int ioEnd, int n){
    if(index>=n || ioStart>ioEnd) return NULL;

    int data = preorder[index++];
    TreeNode* root = new TreeNode(data);
    int position = tMap[data];
    root->left = buildTree(preorder, inorder, tMap, index, ioStart, position-1, n);
    root->right = buildTree(preorder, inorder, tMap, index, position+1, ioEnd, n);
    return root;
}

TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder){
    map<int, int> tMap;
    int n = inorder.size();
    for(int i=0; i<n; i++){
        tMap[inorder[i]]=i;
    }
    int index=0;
    TreeNode* root = buildTree(preorder, inorder, tMap, index, 0, n-1, n);
    return root;
}
