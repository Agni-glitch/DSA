#include <iostream>
using namespace std;
class Node{
    public:
    int coeff;
    int exp;
    Node* next;
    Node(int a,int b){
        coeff=a;
        exp=b;
        next=NULL;
    }
};
class poly{
    Node*head;
    public:
    poly(){
        head=NULL;
    }
    void append(int a,int b){
        Node* newNode= new Node(a,b);
        if (head == NULL || head->exp < b) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && temp->exp > b) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->exp == b) {
            temp->coeff += a;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"0"<<endl;
            return;
        }
        Node* temp=head;
        while (temp!=NULL)
        {
            if(temp->coeff>=0){
                cout<<"+"<<temp->coeff<<"x^"<<temp->exp;
            }else{
                cout<<temp->coeff<<"x^"<<temp->exp;
            }
            temp=temp->next;
        }
        cout<<endl;
    }
    poly addPoly(poly &poly2){
        poly result;
        Node* p1_curr= head;
        Node* p2_curr= poly2.head;
        while (p1_curr != NULL && p2_curr != NULL) {
            if (p1_curr->exp > p2_curr->exp) {
                result.append(p1_curr->coeff, p1_curr->exp);
                p1_curr = p1_curr->next;
            } else if (p1_curr->exp < p2_curr->exp) {
                result.append(p2_curr->coeff, p2_curr->exp);
                p2_curr = p2_curr->next;
            } else {  
                result.append(p1_curr->coeff + p2_curr->coeff, p1_curr->exp);
                p1_curr = p1_curr->next;
                p2_curr = p2_curr->next;
            }
        }
        while (p1_curr != NULL) {
            result.append(p1_curr->coeff, p1_curr->exp);
            p1_curr = p1_curr->next;
        }
        while (p2_curr != NULL) {
            result.append(p2_curr->coeff, p2_curr->exp);
            p2_curr = p2_curr->next;
        }

        return result;
    }
};
int main(){
    poly poly1;
    poly poly2;
    poly poly3;
    poly1.append(5,7);
    poly1.append(8,6);
    poly1.append(-4,6);
    poly1.append(5,4);
    poly1.append(3,3);
    poly1.append(12,2);
    poly1.display();
    poly2.append(4,7);
    poly2.append(8,5);
    poly2.append(8,6);
    poly2.append(9,4);
    poly2.append(7,3);
    poly2.append(6,1);
    poly2.display();
    poly3= poly1.addPoly(poly2);
    poly3.display();
}