class Node {
public:
    int val;
    Node* next;
    Node (int x): val(x), next(NULL) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() : head(NULL), size(0) {}
    
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node* curr = head;
        for(int i=0;i<index;i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
       addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return ;
        
        Node* curr = head;
        Node* temp = new Node(val);
        
        if(index==0){
            temp->next = curr;
            head = temp;
        }
        else{
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            
            temp->next = curr->next;
            curr->next = temp;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index<0) return ;
        
        if(index==0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */