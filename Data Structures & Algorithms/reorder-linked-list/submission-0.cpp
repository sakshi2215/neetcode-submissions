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
    ListNode*reverseList(ListNode* head){
        ListNode*prev = nullptr;
        ListNode* temp = head;

        while(temp!=nullptr){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;

        }
        return prev;
    }
    ListNode*getHalfPartList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        
        ListNode* halfPart = getHalfPartList(head);

        ListNode* reversedPart = reverseList(halfPart->next);
        halfPart->next = nullptr;
        ListNode* temp1 = head;
        ListNode*temp2 = reversedPart;

        while(temp2!=nullptr){
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;
            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2= next2;
        }
        //if()

        //return head;
    }
};
