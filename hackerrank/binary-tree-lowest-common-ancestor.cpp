/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
*/

Node *lca(Node *root, int v1, int v2) {
  Node *temp = root;
  // when v1 or v2 is a root
  if (root->data == v1 || root->data == v2)
    return root;

  while (temp != NULL) {
    // when v1 and v2 are in the opposite sides of the tree
    if ((v1 > temp->data && v2 < temp->data) ||
        (v2 > temp->data && v1 < temp->data))
      return temp;
    // when v1 and v2 are in the left side
    if (temp->data > v1 && temp->data > v2) {
      if (temp->left->data == v1 || temp->left->data == v2) {
        temp = temp->left;  
        break;
      } else {
        temp = temp->left;
      }
    }
    // when v1 and v2 are in the right side
    if (temp->data < v1 && temp->data < v2) {
      if (temp->right->data == v1 || temp->right->data == v2) {
        temp = temp->right;
        break;
      } else {
        temp = temp->right;
      }
    }
}
return temp;
}

// better version
Node *lca_better(Node *root, int v1, int v2) {
    Node *temp = root;

    while (temp != NULL) {
        // when v1 and v2 are in the left side
        if (temp->data > v1 && temp->data > v2) {
            temp = temp->left;
        }
        // when v1 and v2 are in the right side
        else if (temp->data < v1 && temp->data < v2) {
            temp = temp->right;
        }
        // when v1 and v2 are in the opposite side
        else {
            return temp;
        }
    }
    return temp;
}
