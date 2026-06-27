/**
 * Question: 141. Linked List Cycle
 *
 * Approach:
 * - Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
 * - Initialize two pointers:
 *      slow -> moves one step at a time.
 *      fast -> moves two steps at a time.
 * - If the linked list contains a cycle, both pointers will
 *   eventually meet.
 * - If fast reaches NULL, the list has no cycle.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {

        // If the list is empty or has only one node,
        // it cannot contain a cycle.
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // Initialize slow and fast pointers.
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the linked list.
        // Fast moves 2 steps, slow moves 1 step.
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // If both pointers meet, a cycle exists.
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached the end of the list,
        // so there is no cycle.
        return false;
    }
};