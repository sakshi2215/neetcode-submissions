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
    ListNode* reverseList(ListNode* head){
        if(head==nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* getHalfPartOfList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        
        ListNode* getHalf = getHalfPartOfList(head);
        ListNode* reversedList = reverseList(getHalf->next);
        
        getHalf->next = nullptr;
        ListNode* temp1= head;
        ListNode* temp2= reversedList;

        while(temp2!=nullptr){
            ListNode* next1 = temp1->next;
            ListNode* next2= temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1= next1;
            temp2= next2;
        }



        
    }
};
