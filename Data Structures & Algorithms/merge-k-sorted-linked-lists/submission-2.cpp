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
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode*temp = dummy;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                
                list1= list1->next;
            }
            else{
                temp->next= list2;
               
                list2= list2->next;
            }
            temp = temp->next;
        }
        if(list1!=nullptr){
            temp->next = list1;
        }
        if(list2!=nullptr){
            temp->next= list2;
        }
        return dummy->next;
    }
    ListNode* divide(vector<ListNode*>&lists, int l , int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];

        int mid = (l + r)/2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid+1, r);
        return mergeTwoList(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }
};
