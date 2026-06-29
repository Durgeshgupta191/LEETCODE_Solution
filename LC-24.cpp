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
    ListNode* swapPairs(ListNode* head) {

        // If the list has 0 or 1 node, no swapping is needed
        if (head == NULL || head->next == NULL)
            return head;

        // Dummy node to handle swapping of the head node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 'prev' always points to the node before the current pair
        ListNode* prev = dummy;

        // Continue while at least two nodes are available
        while (prev->next != NULL && prev->next->next != NULL) {

            // First and second nodes of the current pair
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Step 1: Connect prev to second
            prev->next = second;

            // Step 2: Connect first to the node after second
            first->next = second->next;

            // Step 3: Connect second to first
            second->next = first;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        // Return the new head
        return dummy->next;
    }
};