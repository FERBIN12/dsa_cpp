#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty";
        } else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail; 
    }

    int getLength() {
        return length;
    }
    
    // We will use this method to test deleteNode on an empty list
    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
        length = 0;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }


        Node* get(int index) {
            if (index < 0 || index >= length) {  
                return nullptr;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {  
                temp = temp->next;
            }
            return temp;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;

            if (index == 0) {
                prepend(value);
                return true;
            }

            if (index == length) {
                append(value);
                return true;
            }

            Node* newNode = new Node(value);
            Node* temp = get(index - 1);

            if (!temp) return false;  // Prevents segmentation fault

            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

            void deleteNode(int index){
                if (index < 0 || index >= length) return ;
                if (index == 0) return deleteFirst();
                if (index == length) return deleteLast();
                Node* prev = get(index-1);
                Node* temp = prev->next;
                prev->next = temp->next;
                delete temp;
                length --;
            }
            void reverse() {
                 Node* temp = head;
                 head = tail;
                 tail = temp;
                 Node* after = temp->next;
                 Node* before = nullptr;
                 for (int i=0;i<length;i++){
                      after = temp->next;
                      temp->next = before;
                      before = temp;
                      temp = after;
                 }
            }

            Node* findMiddleNode(){
                Node* fast = head;
                Node* slow = head;
                while (fast != nullptr && fast->next !=nullptr)
                {
                    slow = slow->next;
                    fast = fast->next->next;
                }
                
                return slow;                
            }

    };

int main() {
    LinkedList* myLinkedList = new LinkedList(0);
    myLinkedList->append(1);        
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    cout<<"The list"<<endl;
    myLinkedList->printList();
    cout<<"The middle node is"<<endl;
    cout<<myLinkedList->findMiddleNode()->value<<endl;

}
