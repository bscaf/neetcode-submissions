/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = nullptr;
        ListNode* lastptr = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* next = nullptr;

        while (curr1 && curr2) {
            if (curr1 -> val > curr2 -> val) {
                next = curr2 -> next;
                if (!result) {
                    result = list2;
                    lastptr = result;
                } else {
                    lastptr -> next = curr2;
                    lastptr = lastptr -> next;
                }
                curr2 = next;
            } else {
                next = curr1 -> next;
                if (!result) {
                    result = list1;
                    lastptr = result;
                } else {
                    lastptr -> next = curr1;
                    lastptr = lastptr -> next;
                }
                curr1 = next;
            }
        }

        if (curr1) {
            if (!result) {
                    result = list1;
            } else {
                lastptr -> next = curr1;
            }
        } 
        if (curr2) {
            if (!result) {
                    result = list2;
            } else {
                lastptr -> next = curr2;
            }
        } 
        return result;
    }
};
