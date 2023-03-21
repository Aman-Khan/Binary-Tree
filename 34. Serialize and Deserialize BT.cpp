    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string encode="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp) encode.append("#,");
            else encode.append(to_string(temp->val)+",");
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout<<encode;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int sz = data.length();
        if(sz==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str)); 
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->left = temp;
                q.push(temp);
            }

            getline(s, str, ',');
            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
