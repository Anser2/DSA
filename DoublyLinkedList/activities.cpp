class ListNode{
    public:
        int data;
        ListNode	*next;
        ListNode	*prev;
    };

    
    class DoublyLinkedList {
        public:
            ListNode* first;  // Points to the head (first node) of the list
            ListNode* last;   // Points to the tail (last node) of the list
            ListNode* PredLoc_; // Stores the address of the logical predecessor during search
            ListNode* Loc_;    // Stores the address of the node containing the searched value
        
            // Constructor
            DoublyLinkedList() : first(nullptr), last(nullptr), PredLoc_(nullptr), Loc_(nullptr) {}
        
            // Destructor to clean up memory
            ~DoublyLinkedList() {
                ListNode* current = first;
                while (current != nullptr) {
                    ListNode* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
        