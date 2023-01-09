// As we know inorder traversal of BST is sorted
// So, in this approach we are using inOrder traversal to convert BST to sorted Linked list. 
// 
// with the help temporary node (dummy node) 
// during inorder traversal (Left, Root, Right)
// when traversal reach at root node (left most root node) we will this that root node to dummy node right pointer and NULL the left pointer of dummy node also
// assign the root node as prev(dummy node) so during traversal inorder next node will be linked to right to this node.
//
// at last we will return the dummy node right pointer
//
// TC - O(N), SC - O(H) H is height of BST
//
void inOrder(TreeNode* root, TreeNode* &prev){
  if(!root) return NULL;
  inOrder(root->left);
  
  prev->left = NULL;
  prev->right = root;
  prev=root;
  
  inOrder(root->right);
}

TreeNode* flatten(TreeNode* root){
    if(!root) return NULL;
  
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* prev = dummy;
  
    inOrder(root, dummy);
    
    prev->left = NULL;
    prev->right = NULL;
    
    delete prev;
    return dummy->right;
}
