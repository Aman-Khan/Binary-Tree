// Approach
// Following the same approach which we use in converting BST to Sorted Linked List
// using inOrder Traversal 

  Node* trav(Node* root, Node* &prev, Node* &head){
        if(!root) return NULL;
        trav(root->left, prev, head);
        if(!prev){
            head = root;
        }
        root->left = prev;
        if(prev){
            prev->right=root;
        }
        prev=root;
        trav(root->right, prev, head);
    }
    Node * bToDLL(Node *root)
    {
        Node* prev = NULL;
        Node* head = NULL;
        trav(root, prev, head);
        return head;
    }
