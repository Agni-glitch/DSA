#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *lchild, *rchild;
    
    Node(int item) {
        data = item;
        lchild = NULL;
        rchild = NULL;
    }
};
class Tree {
public:
    Node *root;
    Tree() {
        root = NULL;
    }
    Node* insert(int item) {
        Node* newNode = new Node(item);
        if (root == NULL) {
            root = newNode;
            return root;
        }
        Node* temp = root;
        Node* parent = nullptr;
        while (temp != NULL) {
            parent = temp;
            if (item < temp->data) {
                temp = temp->lchild;
            } else if (item > temp->data) {
                temp = temp->rchild;
            } else {
                return root;
            }
        }
        if (item < parent->data) {
            parent->lchild = newNode;
        } else {
            parent->rchild = newNode;
        }
        return root;
    }
    void inorder(Node* r) {
        if (r == NULL) return;  
        inorder(r->lchild);
        cout << r->data << " ";  
        inorder(r->rchild);
    }
    void preorder(Node* r) {
        if (r == NULL) return;  
        cout << r->data << " ";
        preorder(r->lchild);
        preorder(r->rchild);
    }
    void postorder(Node* r) {
        if (r == NULL) return;
        postorder(r->lchild);
        postorder(r->rchild);
        cout << r->data << " ";
    }
};
int main() {
    Tree t;
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        t.insert(n);
    }
    cout << "Preorder: ";
    t.preorder(t.root);
    cout << endl;
    cout << "Inorder: ";
    t.inorder(t.root);
    cout << endl;
    cout << "Postorder: ";
    t.postorder(t.root);
    cout << endl;
    return 0;
}