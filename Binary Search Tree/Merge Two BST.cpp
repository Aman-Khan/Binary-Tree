// Approach
// Step 1. convert both BST to sorted linked list
// Step 2. merge them in sorted order
// Step 3. convert the merged linked list to BST
//
// TC - O(N+M) ,SC - O(max(NH, MH)) 
//
// where N & M are no of nodes in BST1 & BST2
// and NH & MH space req to store height during recusion can be N & M in worst case

  Node* mergeBST(Node* root1, Node* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        
        Node* orig = new Node(-1);
        Node* tail = orig;
        
        while(root1!=NULL && root2!=NULL){
            if(root2->data<root1->data){
                tail->right = root2;
                root2=root2->right;
                tail=tail->right;
            }
            else{
                tail->right = root1;
                root1=root1->right;
                tail=tail->right;
            }
        }
        
        if(root1){
            tail->right=root1;
        }
        if(root2){
            tail->right=root2;
        }
        return orig->right;
    }
    
    void inOrder(Node* root, Node* &prev){
        if(!root) return;
        inOrder(root->left, prev);
        prev->left = NULL;
        prev->right = root;
        prev = root;
        inOrder(root->right, prev);
    }
    
    void flatten(Node* &root){
        if(!root) return;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        
        inOrder(root, prev);
        root=dummy->right;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        flatten(root1);
        flatten(root2);

        Node* orig = mergeBST(root1, root2);
