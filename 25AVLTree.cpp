#include <iostream>
using namespace std;
class Node {
public:
    int data, height;
    Node *lchild, *rchild;
    Node(int item) {
        data = item;
        lchild = NULL;
        rchild = NULL;
        height = 1;  
    }
};
class Tree {
public:
    Node* root;
    Tree() {
        root = NULL;
    }

    int getH(Node* r) {
        if (r == NULL) return 0;
        return r->height;
    }

    int getBalance(Node* r) {
        if (r == NULL) return 0;
        return getH(r->lchild) - getH(r->rchild);
    }

    Node* leftRotate(Node* x) {
        Node* y = x->rchild;
        Node* z = y->lchild;
        y->lchild = x;
        x->rchild = z;
        x->height = max(getH(x->lchild), getH(x->rchild)) + 1;
        y->height = max(getH(y->lchild), getH(y->rchild)) + 1;
        return y;  
    }

    Node* rightRotate(Node* x) {
        Node* y = x->lchild;
        Node* z = y->rchild;
        y->rchild = x;
        x->lchild = z;
        x->height = max(getH(x->lchild), getH(x->rchild)) + 1;
        y->height = max(getH(y->lchild), getH(y->rchild)) + 1;
        return y;  
    }
    Node* insert(Node* r, int item) {
        if (r == NULL) {
            return new Node(item);
        }
        if (item < r->data)
            r->lchild = insert(r->lchild, item);
        else if (item > r->data)
            r->rchild = insert(r->rchild, item);
        else
            return r;
        // Update the height of the ancestor node
        r->height = max(getH(r->lchild), getH(r->rchild)) + 1;
        // Get balance factor of this ancestor node to check if it's unbalanced
        int balance = getBalance(r);
        // Left Left Case
        if (balance > 1 && item < r->lchild->data)
            return rightRotate(r);
        // Right Right Case
        if (balance < -1 && item > r->rchild->data)
            return leftRotate(r);
        // Left Right Case
        if (balance > 1 && item > r->lchild->data) {
            r->lchild = leftRotate(r->lchild);
            return rightRotate(r);
        }
        // Right Left Case
        if (balance < -1 && item < r->rchild->data) {
            r->rchild = rightRotate(r->rchild);
            return leftRotate(r);
        }
        return r;
    }
    Node* deleteNode(Node* r,int key){
        if(r==NULL)return r;
        if(key<r->data)
            r->lchild=deleteNode(r->lchild,key);
        else if(key>r->data)
            r->rchild=deleteNode(r->rchild,key);
        else{
            if(r->lchild==NULL){
                Node* temp=r->rchild;
                delete r;
                return temp;
            }
            else if(r->rchild==NULL){
                Node* temp=r->lchild;
                delete r;
                return temp;
            }
        }
        return r;
        if(r==NULL){
            return r;
        }
        r->height=1+max(getH(r->lchild),getH(r->rchild));
        int balance=getBalance(r);
        if(balance>1 && getBalance(r->lchild)>=0){
            return rightRotate(r);
        }
        if(balance>1 && getBalance(r->lchild)<0){
            r->lchild=leftRotate(r->lchild);
            return rightRotate(r);
        }
        if(balance<-1 && getBalance(r->rchild)<=0){
            return leftRotate(r);
        }
        if(balance<-1 && getBalance(r->rchild)>0){
            r->rchild=rightRotate(r->rchild);
            return leftRotate(r);
        }
        return r;
    }
    void inorder(Node* r) {
        if (r == NULL) return;
        inorder(r->lchild);
        cout << r->data << " ";
        inorder(r->rchild);
    }
};
int main() {
    Tree t;
    int choice, value;
    cout << "\nAVL Tree Operations Menu:\n";
    cout << "1. Insert Node\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Delete Node\n";
    cout << "0. Exit\n";
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                t.root = t.insert(t.root, value);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                t.inorder(t.root);
                cout << endl;
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                t.root = t.deleteNode(t.root, value);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}