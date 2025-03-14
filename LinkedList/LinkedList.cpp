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
                cout << temp->value <<endl;
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

        void append (int value){
            Node* newNode = new Node(value);
            if (length ==0){
                head = newNode;
                tail = newNode;
            }else {
                tail->next = newNode;
                tail = newNode;
            }length++;
        }
        void deletelast(){
            if (length == 0) return;
            Node* temp = head;
            Node* pre = head;
            while(temp->next){
                pre = temp;
                temp = temp->next;

            }
            tail= pre;
            tail->next = nullptr;
            length --;
            if (length == 0){
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }
        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }


};

int main(){
    LinkedList* myLinkedList = new LinkedList(1);
    
    myLinkedList->append(2);

    // myLinkedList->get_head();
    // myLinkedList->get_tail();
    // myLinkedList->get_length();
    myLinkedList->printlist();
    cout<<"b4 deleting elements"<<endl;
    myLinkedList->deletelast();
    myLinkedList->printlist();

}