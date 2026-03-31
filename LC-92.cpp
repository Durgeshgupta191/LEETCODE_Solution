
// 92. Reverse Linked List II

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If list is empty or only one node
        if(head == NULL || left == right)
            return head;

        // Dummy node helps handle edge cases (like reversing from head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: move prev to node before 'left'
        ListNode* prev = dummy;
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        // 'curr' will point to first node of the reversing section
        ListNode* curr = prev->next;

        // Step 2: reverse nodes between left and right
        for(int i = 0; i < right - left; i++){

            // Node to be moved
            ListNode* temp = curr->next;

            // Remove temp from its position
            curr->next = temp->next;

            // Insert temp after prev
            temp->next = prev->next;
            prev->next = temp;
        }

        // Step 3: return new head
        return dummy->next;
    }
};