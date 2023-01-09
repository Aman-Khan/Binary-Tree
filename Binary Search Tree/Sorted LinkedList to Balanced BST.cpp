//  flatten BST               to            Balanced BST
// x---(-10)                                     (0)
//       \                                       / \ 
//   x---(-3)                                   /   \
//         \                                 (-3)   (5)
//     x---(0)               ------>          /       \
//           \                               /         \
//       x---(5)                          (-10)        (9)
//             \
//          x---(9)
//                \
//                 x
//
//      (-10)---(-3)---(0)---(5)---(9)---x
//         |      |     |     |     |
//         x      x     x     x     x
//        
// TreeNode buildBalancedBST(TreeNode* root){
//       
//       TreeNode* slow = root;
//       TreeNode* fast = root;
//       TreeNode* mid  = slow;
//
//       mid                                           mid                                                mid                                                                                   
//       root                                           |                                                  |
//       slow                                           |      slow                                        |     slow
//       fast                                           |       |    fast                                  |      |         fast           [fast->right = NULL, so loop stopped]
//      (-10)---(-3)---(0)---(5)---(9)---x            (-10)---(-3)---(0)---(5)---(9)---x          (-10)---(-3)---(0)---(5)---(9)---x         
//         |      |     |     |     |                    |      |     |     |     |                  |      |     |     |     |              
//         x      x     x     x     x                    x      x     x     x     x                  x      x     x     x     x              
//        
//
//       TreeNode* original = slow;
//       mid->right = NULL;                                                             original
//                                                             root   mid                slow
//      at this point root is storing head of list from       (-10)---(-3)---x            (0)--->(5)--->(9)---x   
//
//            original
//              (0)     -- root node of BST is created
//   now recursion will call for original->left  ans original->right
//        
//            
//                          root =  (-10)---(-3)---x
//    original->left = buildBalancedBST(root)     
//    
//       TreeNode* slow = root;
//       TreeNode* fast = root;
//       TreeNode* mid  = slow;
//
//       mid                                           mid                                                                                                                                   
//       root                                           |                                                  
//       slow                                           |      slow                                        
//       fast                                           |       |   fast
//      (-10)---(-3)---x                              (-10)---(-3)---x      [fast=NULL so, loop is stopped]
//        |       |                                     |       |
//        x       x                                     x       x  
//
//      TreeNode* original = slow;
//      mid->right = NULL; 
//        
//      (0)
//      /
//    (-3)
//
//  ...


    TreeNode* buildTree(TreeNode* root){
        if(!root) return NULL;
        if(root->right==NULL) return root;

        TreeNode* slow = root;
        TreeNode* fast = root;
        TreeNode* mid = slow;

        while(fast!=NULL &&  fast->right!=NULL){
            mid = slow;
            slow = slow->right;
            fast = fast->right->right;
        } 

        mid->right = NULL;
        TreeNode* orig = slow;
        orig->left = buildTree(root);
        orig->right = buildTree(slow->right);
        return orig;
    }
