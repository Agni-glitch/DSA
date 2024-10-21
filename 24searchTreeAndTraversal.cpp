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
    Node* search(Node* r,int item){
        if(r==NULL||r->data==item)return r;
        Node* temp= r;
        while (temp!=NULL){
            if(item<temp->data)temp=temp->lchild;
            else if(item>temp->data)temp=temp->rchild;
            else return temp;
        }
        return NULL;
    }
    Node* insertRecursive(Node* r, int item) {
        if (r == NULL) {
            Node* newNode = new Node(item);
            return newNode;
        }
        if (item < r->data)
            r->lchild = insertRecursive(r->lchild, item);
        else if (item > r->data)
            r->rchild = insertRecursive(r->rchild, item);
        return r;
    }
    Node* searchRecursive(Node* r, int item) {
        if (r == NULL || r->data == item)
            return r;
        else if (item < r->data)
            return searchRecursive(r->lchild, item);
        else
            return searchRecursive(r->rchild, item);
    }
    int totalNodes(Node* r) {
        if (r == NULL) return 0;
        return totalNodes(r->lchild) + totalNodes(r->rchild) + 1;
    }
    int totalEN(Node* r) {  // Count external (leaf) nodes
        if (r == NULL) return 0;
        if (r->lchild == NULL && r->rchild == NULL) return 1;
        return totalEN(r->lchild) + totalEN(r->rchild);  // Fix: Call both subtrees
    }
    int totalIN(Node* r) {  // Count internal nodes
        if (r == NULL || (r->lchild == NULL && r->rchild == NULL)) return 0;
        return totalIN(r->lchild) + totalIN(r->rchild) + 1;  // Fix: Call both subtrees
    }
    int smallest(Node* r) {
        if (r == NULL) return -1;
        while (r->lchild != NULL)
            r = r->lchild;
        return r->data;
    }
    int largest(Node* r) {
        if (r == NULL) return -1;
        while (r->rchild != NULL)
            r = r->rchild;
        return r->data;
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
    int height(Node* r) {
        if (r == NULL) return 0;
        int hl = height(r->lchild);
        int hr = height(r->rchild);
        return max(hl, hr) + 1;
    }
    Node* deleteNode(Node* r, int item) {
        if (r == NULL) return r;
        if (item < r->data)
            r->lchild = deleteNode(r->lchild, item);
        else if (item > r->data)
            r->rchild = deleteNode(r->rchild, item);
        else {
            if (r->lchild == NULL) {
                Node* temp = r->rchild;
                delete r;
                return temp;
            }
            else if (r->rchild == NULL) {
                Node* temp = r->lchild;
                delete r;
                return temp;
            }
            r->data = smallest(r->rchild);
            r->rchild = deleteNode(r->rchild, r->data);
        }
        return r;
    }
};
int main() {
    Tree t;
    int choice, value;
    cout << "\nBinary Tree Operations Menu:\n";
    cout << "1. Insert Node\n";
    cout << "2. Preorder Traversal\n";
    cout << "3. Inorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Total Nodes\n";
    cout << "6. Total External (Leaf) Nodes\n";
    cout << "7. Total Internal Nodes\n";
    cout << "8. Find Smallest Node\n";
    cout << "9. Find Largest Node\n";
    cout << "10. Height of Tree\n";
    cout << "11. Delete Node\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                t.root = t.insertRecursive(t.root, value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                t.preorder(t.root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                t.inorder(t.root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                t.postorder(t.root);
                cout << endl;
                break;
            case 5:
                cout << "Total Nodes: " << t.totalNodes(t.root) << endl;
                break;
            case 6:
                cout << "Total External (Leaf) Nodes: " << t.totalEN(t.root) << endl;
                break;
            case 7:
                cout << "Total Internal Nodes: " << t.totalIN(t.root) << endl;
                break;
            case 8:
                cout << "Smallest Node: " << t.smallest(t.root) << endl;
                break;
            case 9:
                cout << "Largest Node: " << t.largest(t.root) << endl;
                break;
            case 10:
                cout << "Height of Tree: " << t.height(t.root) << endl;
                break;
            case 11:
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