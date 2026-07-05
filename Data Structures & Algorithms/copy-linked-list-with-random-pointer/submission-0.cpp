/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return nullptr;
        
         unordered_map<Node*, Node*> nodes;

         Node* curr = head;
         Node* newHead = new Node(curr->val);
         nodes[curr] = newHead;
         Node* newListCurr = newHead;
         while (curr) {            
            if (curr -> random) {
                if (nodes.contains(curr -> random)) {
                    newListCurr -> random = nodes[curr -> random];
                } else {
                    newListCurr -> random = new Node(curr -> random -> val);
                    nodes[curr -> random] = newListCurr -> random;
                }
            }
             else {
                newListCurr -> random = nullptr;
            }

            curr = curr -> next;
            if (curr) {
                if (nodes.contains(curr)) {
                    newListCurr -> next = nodes[curr];
                } else {
                    nodes[curr] = new Node(curr -> val);
                    newListCurr -> next = nodes[curr];
                }
            }

            newListCurr = newListCurr -> next;
         }
        return newHead;
    }
};
