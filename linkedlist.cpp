#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        this->data = val;
        this->next = NULL;
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

}

void reverseList(Node* &head){
    Node* current = head;
    Node* prevNode = NULL;
    Node* nextNode;

     while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    
    head = prevNode;
}

Node* reverseKNode(Node* &head, int pos){
    Node* current = head;
    Node* prevNode = NULL;
    Node* nextNode;
    int count = 0;

    while(current != NULL && count<pos){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
        count++;
    }
    if(nextNode != NULL){
        head->next = reverseKNode(nextNode, pos);
    }
    return prevNode;
}

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

//appedn last k nodes in the first

int length(Node* head){
    Node* temp = head;
    int l = 0;
    while(temp){
        temp = temp->next;
        l++;
    }
    return l;
}

void appendLastKNodes(Node* &head, int k){
    int len = length(head);
    cout<<"list length: "<<len<<endl;
    int flag = 1;
    Node* current = head;
    Node* newTail;
    Node* newHead;
    while(current->next != NULL){
        if(flag == len-k){
            newTail = current;
        }
        if(flag == len-k+1){
            newHead = current;
        }
        flag++;
        current = current->next;
    }
    newTail->next = NULL;
    Node* temp = newHead;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head;
    head = newHead;
}

Node* mergeTwoShortedList(Node* &head, Node* &head1){
    Node* temp = head;
    Node* temp1 = head1;

    Node* tempNode = new Node(4);
    Node* dummyNode = tempNode;
    while(temp!=NULL && temp1!=NULL){
        if(temp->data > temp1->data){
            dummyNode->next = temp1;
            temp1 = temp1->next;
        }else{
            dummyNode->next = temp;
            temp = temp->next;
        }
        dummyNode = dummyNode->next;
    }
    while(temp!=NULL){
        dummyNode->next = temp;
        temp = temp->next;
        dummyNode = dummyNode->next;
    }
    while(temp1!=NULL){
        dummyNode->next = temp1;
        temp1 = temp1->next;
        dummyNode = dummyNode->next;
    }
    return tempNode->next;
}

void deleteAtPos(Node* &head, int val){
    Node* current = head;
    if(current->data == val){
        Node* todelete = current;
        head = current->next;
        delete todelete;
        return;
    }
    Node* BeforeNodeDelete = nullptr;
    while(current->next){
        if(current->next->data == val){
            BeforeNodeDelete = current;
            break;
        }
        current = current->next;
    }
    if(BeforeNodeDelete != nullptr){
        Node* todelete = BeforeNodeDelete->next;
        BeforeNodeDelete->next = BeforeNodeDelete->next->next;
        delete todelete;
        return;
    }
    cout<<"This element is not present in linkdlist"<<endl;
}

void makeCycle(Node* &head, int pos){
    int count = 0;
    Node* current = head;
    Node* cycleAtPos = nullptr;
    while(current->next){
        if(pos == count){
            cycleAtPos = current;
        }
        current = current->next;
        count++;
    }
    current->next = cycleAtPos;
}

bool detectCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    bool loopBreak = false;
    while(fast){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
        
    }
    return false;
}

void displayList(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

void evenNodeAfterOddList(Node* &head){
    Node* current = head;
    int count = 1;
    Node* dummyOdd = new Node(1);
    Node* dummyEven = new Node(2);
    Node* d1 = dummyOdd;
    Node* d2 = dummyEven;
    
    while(current!=NULL){
        if(count%2==0){
            d2->next = current;
            d2 = d2->next;
        }else{
            d1->next = current;
            d1 = d1->next;
        }
        current = current->next;
        count++;
    }
    d2->next = NULL;
    d1->next = dummyEven->next;
    head = dummyOdd->next;
}



int main(){

Node* head = nullptr;
Node* head1 = nullptr;
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
for(int i=0;i<10;i++){
    insertAtTail(head, arr[i]);
}
int arr1[] = {2, 5, 10, 14, 15, 16, 17};
for(int i=0;i<7;i++){
    insertAtTail(head1, arr1[i]);
}
displayList(head);
// displayList(head1);
// Node* newHead = mergeTwoShortedList(head, head1);

// displayList(newHead);

// Node* newHead = reverseKNode(head, 3);
// reverseList(head);
// deleteAtPos(head, 4);
// makeCycle(head, 4);

// appendLastKNodes(head, 2);
// displayList(head);

evenNodeAfterOddList(head);
displayList(head);

// displayList(newHead);
// cout<<detectCycle(head)<<endl;
}
