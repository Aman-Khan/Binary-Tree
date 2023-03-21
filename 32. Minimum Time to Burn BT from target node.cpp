Node* getTarget(Node* root, int target){
        if(!root) return NULL;
        else if(root->data == target) return root;
        Node* l = getTarget(root->left, target);
        Node* r = getTarget(root->right, target);
        if(l) return l;
        else return r;
    }
    void mapWithParent(Node* root, map<Node*, Node*> &nodeToPar){
        if(!root) return;
        if(root->left) nodeToPar[root->left]=root;
        if(root->right) nodeToPar[root->right]=root;
        mapWithParent(root->left, nodeToPar);
        mapWithParent(root->right, nodeToPar);
    }
    int minTime(Node* root, int target) 
    {
        int tk = 0;
        if(!root) return tk;
        map<Node*, Node*> nodeToPar;
        mapWithParent(root, nodeToPar);
        map<Node*, bool> vis;
        Node* tar = getTarget(root, target);
        if(!tar) return tk; 
        queue<Node*> q;
        q.push(tar);
        vis[tar];
                
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            for(int i=0; i<sz; i++){
                Node* temp = q.front();
                // cout<<temp->data<<" ";
                q.pop();
                if(temp->left && vis.find(temp->left)==vis.end()){
                    q.push(temp->left);
                    vis[temp->left];
                    flag = true;
                }
                if(temp->right && vis.find(temp->right)==vis.end()){
                    q.push(temp->right);
                    vis[temp->right];
                    flag = true;
                }
                if(nodeToPar.find(temp)!=nodeToPar.end() && vis.find(nodeToPar[temp])==vis.end()){
                    q.push(nodeToPar[temp]);
                    vis[nodeToPar[temp]];
                    flag = true;
                }
            }
            // cout<<endl;
            tk++;
        }
        return tk-1;
    }
