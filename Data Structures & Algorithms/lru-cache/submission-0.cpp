class Node{
    public:
    int key;
    int value;
    Node*next;
    Node*prev;

   

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

class LRUCache {
private:

unordered_map<int, Node*>cache;
int capacity;
Node*left;
Node*right;



public:
    LRUCache(int capacity) {
        cache.clear();
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }
    
    void insert(Node* temp){
         
        Node* prevNode = right->prev;
        prevNode->next = temp;
        temp->prev = prevNode;
        temp->next = right;
        right->prev = temp;


    }
    void remove(Node* temp){
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        temp->prev = nullptr;
        temp->next = nullptr;
        prevNode->next= nextNode;
        nextNode->prev = prevNode;
    }
    int get(int key) {
        //check if it contains that key or not
        if(cache.find(key)!=cache.end()){
            Node* temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > capacity){
            Node* leftnext = left->next;
            remove(leftnext);
            cache.erase(leftnext->key);
            delete(leftnext);
        }
    }
};
