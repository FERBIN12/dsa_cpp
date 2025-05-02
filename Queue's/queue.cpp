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

class Queue{
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int value){
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length =1;
    }

    void printQueue(){
        Node* temp = first;
        while(temp){
            cout<< temp->value<<endl;
            temp = temp->next;
        }
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        if (length == 0) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue(){
        if (length ==0){ 
            return INT8_MIN;
        }
        Node* temp = first;
        int dequeued_value = first->value;
        if (length ==1){
            first = nullptr;
            last = nullptr;
        }else{
            first = first->next;
                      
        }
        delete temp;
        length --;
        return dequeued_value;
    }
};

int main(){
    Queue* myq = new Queue(0);
    myq->enqueue(1);
    cout<<"Removed value: "<<myq->dequeue()<<endl;

    cout<< "Present Queue"<<endl;
    myq->printQueue();

}