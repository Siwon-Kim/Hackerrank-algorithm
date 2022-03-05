/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node* newNode = new Node(data);
        if(root == NULL) {
            root = newNode;
        }
        else {
            Node* temp = root;
            while(temp!=NULL) {
                if(temp->data < data) {
                    if(temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    } 
                    else temp = temp->right;
                } else {
                    if(temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    else temp = temp->left;
                }
            }
        }
        
        return root;
    }
