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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // slow está ahora en la mitad de la lista enlazada
        //revertimos a partir de slow
        ListNode* curr = slow -> next;
        slow -> next = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tmp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tmp;
        }
        slow = prev;
        // ordenamos intercalando
        while (slow) {
            ListNode* fst_half_tmp = head -> next;
            ListNode* snd_half_tmp = slow -> next;
            head -> next = slow;
            slow -> next = fst_half_tmp;
            head = fst_half_tmp;
            slow = snd_half_tmp;
        }
    }
};
