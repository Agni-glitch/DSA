#include <bits/stdc++.h>
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
    vector<int> levelOrderTraversal() {
        vector<int> result;
        if (root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result.push_back(current->data);
            if (current->lchild != NULL) {
                q.push(current->lchild);
            }
            if (current->rchild != NULL) {
                q.push(current->rchild);
            }
        }
        return result;
    }
    vector<int> preorderTraversal() {
        vector<int> result;
        if (root == NULL) return result;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* current = st.top();
            st.pop();
            result.push_back(current->data);
            if (current->rchild != NULL) {
                st.push(current->rchild);
            }
            if (current->lchild != NULL) {
                st.push(current->lchild);
            }
        }
        return result;
    }
    vector<int> inorderTraversal() {
        vector<int> result;
        stack<Node*> st;
        Node* current = root;
        while (current != NULL || !st.empty()) {
            while (current != NULL) {
                st.push(current);
                current = current->lchild;
            }
            current = st.top();
            st.pop();
            result.push_back(current->data);
            current = current->rchild;
        }
        return result;
    }
};
int main() {
    Tree t;
    for (int i = 0; i < 8; i++) {
        int n;
        cin >> n;
        t.insert(n);
    }
    vector<int> levelOrder = t.levelOrderTraversal();
    cout << "Level Order Traversal: ";
    for (int i : levelOrder) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> preorder = t.preorderTraversal();
    cout << "Preorder Traversal: ";
    for (int i : preorder) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> inorder = t.inorderTraversal();
    cout << "Inorder Traversal: ";
    for (int i : inorder) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}