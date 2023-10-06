#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoblyLinkedList{
    public:
    Node* head;
    Node* tail;
    
    DoblyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(!tail){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next  = newNode;
        tail = newNode;

    }
    void insertAtFront(int data){
        Node* newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    void displayForwardList(){
        Node* current = head;
        while(current){
            cout<<current->data<<" ";
            current = current->next;
        }
    }
};

int main(){
    DoblyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.displayForwardList();
    cout<<endl;
    dll.insertAtFront(6);
    dll.insertAtFront(7);
    dll.displayForwardList();
}