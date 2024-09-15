#include <bits/stdc++.h>

using namespace std;
// Building Tree structure.
struct Node {
    int data{};
    Node *left{}, *right{};
};

Node *get_node(int ele) {
    Node *ptr = new Node();
    ptr->data = ele;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

Node *insert_Tree(int ele, Node *root) {
    if (root == NULL) {
        root = get_node(ele);
        return root;
    }
    else if (ele < root->data) {
        root->left = insert_Tree(ele, root->left);
    }
    else if (ele > root->data) {
        root->right = insert_Tree(ele, root->right);
    }
    return root;
}

Node *insert_list(vector < int > vec1, Node *root) {
    for (int i=0; i < vec1.size(); i++) {
        root = insert_Tree(vec1[i], root);
    }
    return root;
}

void print_tree(Node *root) {
    if (root == NULL ) {
        return;
    } else {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}
void print_inorder(Node *root) {
    // this function print tree in inorder or ascending order.
    if (root == NULL ) {
        return;
    } else {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}

void print_postorder(Node *root) {
    // this function print in post order or right to left.
    if (root == NULL ) {
        return;
    } else {
        print_tree(root->left);
        print_tree(root->right);
        cout << root->data << " ";
    }
}

void print_preorder(Node *root) {
    // this function print tree in pre order or from left to right.
    if (root == NULL ) {
        return;
    } else {
        cout << root->data << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

void delete_element_tree(int ele, Node *root) {
    if (root == NULL) {
        return;
    } else if (ele == root->data) {
        // delete the element.
        // if no child of current node
        if (root->left == NULL && root->right == NULL ) {
            root = NULL;
        } else if (root->left == NULL) {
            // current node has only right node.
            root = root->right;
        } else if  (root->right == NULL) {
            // current node has only left node.
            root = root->left;
        } else {
            // current node has both child node.
            // Either find largest node in left sub tree and replace that with current node.
            // or find smallest node in right sub tree and replace that with current node.

            // finding largest node in left sub tree.
            Node *temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            // we have reached the node to replace.
            root->data = temp->data;
            delete_element_tree(temp->data, root->left);
        }
    
    } else if (ele < root->data) {
        delete_element_tree(ele, root->left);
    } else if (ele > root->data) {
        delete_element_tree(ele, root->right);
    }
    return;
}

int main() {
    Node *root = new Node();
    root = NULL;
    // insert single data into tree.
    root = insert_Tree(20, root);
    root = insert_Tree(2, root);
    print_tree(root);
    cout << endl;

    // insert list of elements into tree
    vector < int > vec = {10, 30, 5, 25, 4, 13, 29, 7, 12};
    root = insert_list(vec, root);
    // print tree.
    print_tree(root);
    cout << endl;

    // Printing in different orders.
    cout << "\nIn-order: ";
    print_inorder(root);

    cout << "\nPre-order: ";
    print_preorder(root);

    cout << "\nPost-order: ";
    print_postorder(root);

    // delete the elements from tree.
    delete_element_tree(13, root);
    cout << "\nAfter deleting elements: ";
    print_tree(root);

    return 0;

}