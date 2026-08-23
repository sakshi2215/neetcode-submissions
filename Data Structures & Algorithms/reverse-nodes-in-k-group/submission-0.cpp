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
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* current = head;

        while(k> 0){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            k--;

        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(count < k && temp!=nullptr){
            temp = temp->next;
            count++;
        }
        if(count != k) return head;
        else{
            temp = reverseKGroup(temp, k);
            ListNode* reversedHead = reverse(head, k);
            head->next = temp;
            head = reversedHead;
            
        }
      return head;
        

    }
};
