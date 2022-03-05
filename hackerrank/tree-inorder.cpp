void inOrder(Node *root) {
    if(root->left != NULL) 
        inOrder(root->left);
    std::cout << root->data << ' ';
    if(root->right != NULL) {
        inOrder(root->right);
    }
}
