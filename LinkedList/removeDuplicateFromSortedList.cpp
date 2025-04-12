#include <iostream>
#include <unordered_set>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            unordered_set<int> values;

            ListNode* current = head;
            ListNode* prev = nullptr;

            while (current != nullptr){
                if (values.find(current->val) != values.end()){
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }else{
                    values.insert(current->val);
                    prev = current;
                    current = current->next;
                }
            }
            return head;
            
        }
    };
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    // Main function
int main() {
    // Create list1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1, new ListNode(1, new ListNode(4)));

 
    // Merge lists
    Solution merger;
    ListNode* merged = merger.deleteDuplicates(l1);

    // Print merged list
    cout << "Merged List: ";
    printList(merged);

    return 0;
}