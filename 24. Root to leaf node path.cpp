    void track(TreeNode* root, vector<string> &allPath, string path){
        if(!root) return;
        if(!root->left && !root->right){
            path+=to_string(root->val);
            allPath.push_back(path);
            return;
        }
        path+=to_string(root->val);
        track(root->left, allPath, path+"->");
        track(root->right, allPath, path+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> allPath;
        track(root, allPath, path);
        return allPath;
    }
