/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mpp;


        Node* current = head;
        mpp[nullptr] = nullptr;
        while(current!=nullptr){
            Node* temp = new Node(current->val);
            mpp[current] = temp;
            current = current->next;
        }
        
        current = head;
        while(current!=nullptr){
            Node*copy = mpp[current];
            copy->next = mpp[current->next];
            copy->random = mpp[current->random];
            current = current->next;
            copy = copy->next;
        }
        return mpp[head];
    }
};
