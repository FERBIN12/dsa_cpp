#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class Stack{
private:
    Node* top;
    int height;

public:
    Stack(int value){
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printstack(){
        Node* temp = top;
        while(temp){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;   // This is the fix
        height++;
    }

    int pop(){
        if (height ==0){
            return INT32_MIN;
        }
        Node* temp = top;
        int popped_val = top->value;
        top = top->next;
        delete temp;
        height --;
        return popped_val;
        
    }
    
};

int main(){
    Stack* mystk = new Stack(4);
    mystk->push(2);
    mystk->push(1);
    mystk->push(3);
    mystk->push(9);
    cout<<mystk->pop();
    
}