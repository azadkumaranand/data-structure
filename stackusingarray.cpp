#include <iostream>
using namespace std;

#define n 100

class Stack{
    public:
    int arr[100];
    int top = -1;

    void push(int x){
        if(top == n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top == -1){
            cout<<"No elements to pop"<<endl;
            return;
        }
        top--;
    }
    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    int Top(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
        }
        return arr[top];
    }
    void display(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        for(int i=0; i<top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.push(6);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
}