//recursive
void traverse(TreeNode* root, map<int, map<int, multiset<int>>>& vertex, int x, int y){
if(!root) return;
vertex[x][y].insert(root->val);
traverse(root->left, vertex, x-1, y+1);
traverse(root->right, vertex, x+1, y+1);
}

//iterative
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> coordiMap;
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            coordiMap[x][y].insert(temp.first->val);
            if(temp.first->left){
                q.push({temp.first->left, {x-1, y+1}});
            }
            if(temp.first->right){
                q.push({temp.first->right, {x+1, y+1}});
            }
        }   
        for(auto p:coordiMap){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
