//iterative
  void flatten(TreeNode* &root) {
        if(root==NULL) return;
        TreeNode* real=new TreeNode(-1);
        TreeNode* tail = real;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            tail->right=temp;
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            tail = temp;
        }
        while(real!=NULL){
            cout<<real->val<<" ";
            real=real->right;
        }
        root = real->right;
    }

//recursion
  void flat(TreeNode* root, TreeNode* &prev){
        if(!root) return;
        flat(root->right, prev);
        flat(root->left, prev);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten(TreeNode* &root) {
        TreeNode* prev=NULL;
        flat(root, prev);
