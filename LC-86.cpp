
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
    ListNode* partition(ListNode* head, int x) {

        // Dummy node for values smaller than x
        ListNode* dummy1 = new ListNode(0);

        // Dummy node for values greater than or equal to x
        ListNode* dummy2 = new ListNode(0);

        // Traverse the original linked list
        ListNode* temp = head;

        // Pointers to the last nodes of both new lists
        ListNode* temp1 = dummy1;
        ListNode* temp2 = dummy2;

        while (temp != NULL) {

            // If the current value is smaller than x,
            // add a new node to the first list
            if (temp->val < x) {
                temp1->next = new ListNode(temp->val);

                // Move temp1 to the newly added node
                temp1 = temp1->next;
            }
            else {
                // If the value is >= x,
                // add a new node to the second list
                temp2->next = new ListNode(temp->val);

                // Move temp2 to the newly added node
                temp2 = temp2->next;
            }

            // Move to the next node of the original list
            temp = temp->next;
        }

        // Connect the smaller-values list
        // to the list containing values >= x
        temp1->next = dummy2->next;

        // Return the actual head, skipping dummy1
        return dummy1->next;
    }
};
