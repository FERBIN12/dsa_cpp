# include <iostream>

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

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        void printlist(){
            Node* temp = head;
            while (temp){
                cout <<"List:"<< temp->value <<endl;
                temp = temp->next;
            }
        }
        void get_head(){
            cout<< "Head:"<< head->value<<endl;
        }
        void get_tail(){
            cout<<"Tail:"<< tail->value<<endl;
        }
        void get_length(){
            cout<<"Length:"<< length<<endl;
        }
};

int main(){
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->get_head();
    myLinkedList->get_tail();
    myLinkedList->get_length();
    myLinkedList->printlist();

}