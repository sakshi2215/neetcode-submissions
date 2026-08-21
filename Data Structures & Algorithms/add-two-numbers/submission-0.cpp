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
        int sum =0;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);

        ListNode* temp = dummy;

        while(l1!=nullptr && l2!=nullptr){
            sum = l1->val + l2->val + carry;
            int rem = sum %10;
            carry = sum/10;
            l1 = l1->next;
            l2= l2->next;

            ListNode* newNode = new ListNode(rem);
            temp->next = newNode;
            temp = newNode;             
        }
        while(l1!=nullptr){
            sum = l1->val + carry;
            int rem = sum % 10;
            carry = sum/10;
            l1= l1->next;

            ListNode* newNode = new ListNode(rem);
            temp->next = newNode;
            temp = newNode;
        }
        while(l2!=nullptr){
            sum = l2->val + carry;
            int rem = sum % 10;
            carry = sum/10;
            l2= l2->next;

            ListNode* newNode = new ListNode(rem);
            temp->next = newNode;
            temp = newNode;
        }
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
};
