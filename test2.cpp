#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
        // this->prev = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next){
       current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteNode(Node* &head, int val){
    Node* current=head;
    while(current){
        if(current->data == val){
            Node* prevNode = current->prev;
            Node* nextNode = current->next;
            Node* todelete = current;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete todelete;
            return;
        }
        current = current->next;
    }
}

void displayList(Node* &head){
    Node* current = head;
    while(current){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){

Node* head = nullptr;

insertAtTail(head, 1);
insertAtTail(head, 2);
insertAtTail(head, 3);
insertAtTail(head, 4);
insertAtTail(head, 5);
insertAtTail(head, 6);
insertAtTail(head, 7);
displayList(head);
deleteNode(head, 4);
displayList(head);

}