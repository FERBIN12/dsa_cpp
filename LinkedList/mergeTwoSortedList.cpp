#include <iostream>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class to merge two sorted lists
class mergeTwoSortedList {
public:
    ListNode* mergeTwoSorted(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next; // advance the dummy pointer
        }

        if (list1 != nullptr) dummy->next = list1;
        if (list2 != nullptr) dummy->next = list2;

        return res->next;
    }
};

// Utility function to print a linked list
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
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    // Create list2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    // Merge lists
    mergeTwoSortedList merger;
    ListNode* merged = merger.mergeTwoSorted(l1, l2);

    // Print merged list
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
