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

        // Dummy node banaya taaki head handle karna easy ho jaye
        ListNode* newNode = new ListNode();

        // curr merged list ke last node ko point karega
        ListNode* curr = newNode;

        // Jab tak dono lists me elements hain
        while (list1 != NULL && list2 != NULL) {

            // Chhoti value wali node ko merged list me jodo
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            // curr ko aage badhao
            curr = curr->next;
        }

        // Agar list1 me nodes bachi hain to attach kar do
        if (list1) {
            curr->next = list1;
        }
        // Warna list2 ki remaining nodes attach kar do
        else {
            curr->next = list2;
        }

        // Dummy node ko skip karke actual head return karo
        return newNode->next;
    }
};