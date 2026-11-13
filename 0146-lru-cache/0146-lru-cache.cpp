class LRUCache {
public:
     class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    map<int,Node*> m;
    int cap;
    Node* left=new Node(-1,-1);
    Node* right=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        m.clear();
        left->next=right;
        right->prev=left;
    }
    void insert(Node* node){
       Node* temp=left->next;
       node->next=temp;
       node->prev=left;
       left->next=node;
       temp->prev=node;


    }

    void delete_node(Node* node){
        Node* prevv = node -> prev;
        Node* nextt = node -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* b=m[key];
         m.erase(key);
        delete_node(b);
        insert(b);
        m[key]=left->next;
        return b->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* curr=m[key];
            m.erase(key);
            delete_node(curr);
        }
        if(m.size()==cap){
            m.erase(right-> prev -> key);
            delete_node(right -> prev);
        }
        insert(new Node(key,value));
        m[key]=left->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */