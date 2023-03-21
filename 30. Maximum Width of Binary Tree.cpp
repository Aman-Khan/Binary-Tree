    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if(!root) return maxWidth;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int sz = q.size();
            int minAtLvl;
            int wS, wE;
            for(int i=0; i<sz; i++){
                if(i==0){
                    minAtLvl = q.front().second;
                    wS = minAtLvl;
                }
                TreeNode* node = q.front().first;
                int ind = q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left, (long long)2*(ind-minAtLvl)});
                }
                if(node->right){
                    q.push({node->right, (long long)2*(ind-minAtLvl)+1});
                }
                wE = ind;
            }
            maxWidth = max(maxWidth, wE-wS+1);
        }
        return maxWidth;
    }
