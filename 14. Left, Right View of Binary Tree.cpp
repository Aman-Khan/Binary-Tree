//using map
//left
void view(Node* root, map<int, int> &xMap, int lvl){
    if(root==NULL) return;
    if(xMap.find(lvl)==xMap.end()){
        xMap[lvl]=root->data;
    }
    if(root->left) view(root->left, xMap, lvl+1);
    if(root->right) view(root->right, xMap, lvl+1); 
}

//right
void view(Node* root, map<int, int> &xMap, int lvl){
    if(root==NULL) return;
    xMap[lvl]=root->data;
    if(root->left) view(root->left, xMap, lvl+1);
    if(root->right) view(root->right, xMap, lvl+1); 
}

//without map
//left
void leftView(Node* root, int lvl, vector<int> &ans){
    if(root==NULL) return;
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    leftView(root->left, lvl+1, ans);
    leftView(root->right, lvl+1, ans);
}

//right
void rightView(Node* root, int lvl, vector<int> &ans){
    if(root==NULL) return;
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    rightView(root->right, lvl+1, ans);
    rightView(root->left, lvl+1, ans);
}
