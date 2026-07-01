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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify list creation
        ListNode* dummy = new ListNode(0);

        // Pointer used to build the answer list
        ListNode* curr = dummy;

        // Stores carry generated after addition
        int carry = 0;

        // Continue until both lists are finished and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry) {

            // Start sum with the previous carry
            int sum = carry;

            // Add current node value from first list (if exists)
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add current node value from second list (if exists)
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Calculate carry for the next digit
            carry = sum / 10;

            // Create a new node with the current digit
            curr->next = new ListNode(sum % 10);

            // Move to the newly created node
            curr = curr->next;
        }

        // Return the head of the result list
        return dummy->next;
    }
};