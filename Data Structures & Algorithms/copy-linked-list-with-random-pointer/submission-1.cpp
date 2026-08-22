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

        if (head == nullptr)
            return nullptr;

        Node* temp = head;

        // Step 1: Create copy nodes and insert them
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);

            Node* next = temp->next;

            temp->next = newNode;
            newNode->next = next;

            temp = next;
        }

        // Step 2: Copy random pointers
        temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;
            Node* nextTemp = copyNode->next;

            if (temp->random != nullptr) {
                copyNode->random = temp->random->next;
            }

            temp = nextTemp;
        }

        // Step 3: Separate the two lists
        temp = head;
        Node* copyHead = head->next;

        while (temp != nullptr) {
            Node* copyNode = temp->next;
            Node* nextTemp = copyNode->next;

            temp->next = nextTemp;

            if (nextTemp != nullptr) {
                copyNode->next = nextTemp->next;
            } else {
                copyNode->next = nullptr;
            }

            temp = nextTemp;
        }

        return copyHead;
    }
};
