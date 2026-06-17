class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while(temp && temp->next) {

            // Duplicate found
            if(temp->val == temp->next->val) {

                // Skip duplicate node
                temp->next = temp->next->next;
            }
            else {

                // Move forward only when values differ
                temp = temp->next;
            }
        }

        return head;
    }
};