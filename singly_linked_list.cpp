#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:

        Node* head;
        LinkedList(): head(nullptr) {}; //CONSTRUCTOR -> head being the last element, means the list is empty.

        bool isEmpty() {
            if(head == nullptr){
                cout << "True. List is empty. " << endl;
                return true;
            }
            else return false;
        }

        void insertAtFront(int val){

            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = head;
            head = newNode;

            cout << "Inserted " << val << " in the front. " << endl;
        }

        void insertAtEnd(int val) {

            Node* newNode = new Node;
            newNode->next = nullptr;
            newNode->data = val;

            if (isEmpty()){ //if list is empty, new node becomes the last node

                head = newNode;
            }
            else { // else traverse towards the end and then insert
                Node* temp = head;
                while(temp->next != nullptr){
                    temp=temp->next;
                }
                temp->next = newNode;             
            }
            cout << "Inserted " << val << " in the end. " << endl;

        }

        bool search(int val) {
            Node* temp = head;
            while (temp) {
                if (temp->data == val) {
                    cout << "Found " << val << " in the list." << endl;
                    return true;
                }
                temp = temp->next;
            }
            cout << val << " not found in the list." << endl;
            return false;
        }
    
        void deleteNode(int val) {
            if (isEmpty()) {
                cout << "List is empty. Cannot delete " << val << "." << endl;
                return;
            }
    
            if (head->data == val) { // If the node to delete is the head
                Node* temp = head;
                head = head->next;
                delete temp;
                cout << "Deleted " << val << " from the list." << endl;
                return;
            }
    
            Node* temp = head;
            while (temp->next && temp->next->data != val) {
                temp = temp->next;
            }
    
            if (temp->next == nullptr) {
                cout << val << " not found in the list." << endl;
            } else {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                cout << "Deleted " << val << " from the list." << endl;
            }
        }
    
        void destroyList() {
            Node* temp = head;
            while (head) {
                temp = head;
                head = head->next;
                delete temp;
            }
            cout << "List destroyed." << endl;
        }

        void printList() {
            if (isEmpty()) { return; }
            Node* temp = head;
            temp = head;
            while(temp){
                cout<< temp->data << "->";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }        
}; 

int main() {

    LinkedList ll;
    ll.insertAtFront(5);
    ll.insertAtFront(6);
    ll.insertAtFront(7);
    ll.insertAtEnd(10);
    ll.printList();
    cout << endl;
    ll.destroyList();
    ll.printList();

}