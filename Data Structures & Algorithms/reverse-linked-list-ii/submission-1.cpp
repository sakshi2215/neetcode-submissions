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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        for(int i=0; i<left-1; i++){
            prev = prev->next;
        }
        ListNode* subListHead = prev->next;
        ListNode*subListTail = subListHead;
        for(int i=0; i<right-left; i++){
            subListTail = subListTail->next;
        }

        ListNode* next = subListTail->next;

        subListTail->next = nullptr;
        prev->next = reverseList(subListHead);
        subListHead->next = next;

        return dummy->next;






    }
};