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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size = 0;
        while (curr) {
            size++;
            curr = curr -> next;
        }
        int nthFromEnd = size - n;

        curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < nthFromEnd; i++) {
            prev = curr;
            curr = curr -> next;
        }
        if (prev) {
            prev -> next = curr -> next;
            curr -> next = nullptr;
        } else {
            head = curr -> next;
        }
        return head;
    }
};
