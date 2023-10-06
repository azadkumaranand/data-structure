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
    // Node* head;
    // Linkedlist(){
    //     head = nullptr;
    // }
    void insertelement(int data, Node* &head){
        Node* newNode = new Node(data);
        // bool setHead = false;
        if(!head){
            head = newNode;
            return;
        }
        //procedural method
        /*
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
        */
        if(!head->next){
            head->next = newNode;
            return;
        }
        insertelement(data, head->next);
        
    }
    void insertAtFront(int data, Node* &head){
        Node* new_node = new Node(data);
        if(!head){
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    bool search(int key, Node* head){
        // Node* current = head;
        if(!head){
            cout<<"LinkedList is blank"<<endl;
            return false;
        }
        if(head->data == key){
            return true;
        }
        //procedural process
        /*
        while(current->next){
            if(current->data == key){
                return true;
            }
            current = current->next;
        }
        */

        //recurtion method

        if(!head->next){
            return false;
        }
        return search(key, head->next);
    }

    void displaylist(Node* head){
        Node* current = head;
        while (current)
        {
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"NULL";
    }

    void deleteNode(int key, Node* &head){
        if(!head){
            cout<<"LinkedList is blank"<<endl;
            return;
        }
        if(!head-next){
            delete head;
            return;
        }
        Node* prev;
        Node* current = head;
        Node* next;
        while(current){
            next = current->next;
            if(current->data == key){
                prev->next = next;
                delete current;
                return;
            }
            prev = current;
            current = next;
        }
    }
    
    void displayRecursive(Node* head){
        if(head){
            cout<<head->data<<"=>";
            head = head->next;
            displayRecursive(head);
        }
    }
};

int main(){
    Node* head = nullptr;
    Linkedlist my_list;
    my_list.insertelement(1, head);
    my_list.insertelement(2, head);
    my_list.insertelement(3, head);
    my_list.insertelement(4, head);
    my_list.insertelement(5, head);
    my_list.insertelement(6, head);
    my_list.insertAtFront(7, head);
    my_list.delete(3, head);
    cout<<my_list.search(3, head)<<endl;
    my_list.displayRecursive(head);
}