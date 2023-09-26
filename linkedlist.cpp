#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Linkedlist{
    public:
    Node* head;
    Linkedlist(){
        head = nullptr;
    }
    void insertelement(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
    }
    void displaylist(){
        Node* current = head;
        while (current)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        
    }
};

int main(){
    Linkedlist my_list;
    my_list.insertelement(1);
    my_list.insertelement(2);
    my_list.insertelement(3);
    my_list.insertelement(4);
    my_list.insertelement(5);
    my_list.insertelement(6);
    my_list.displaylist();
}